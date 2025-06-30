#!/bin/bash

# Records the initial mouse position
# Moves/clicks as usual
# After any random movement, checks the distance from the original position
# If the cursor drifts beyond a threshold (e.g., 50 pixels), it moves back to the starting position

# How to implement smooth glide back?
# Calculate the difference vector (dx, dy) between current and start.
# Move the mouse in small increments along that vector.
# Add a tiny delay between each incremental move to create a smooth motion.
#

# Configurable thresholds
PROB_MOVE=8           # % chance to move
MIN_MOVE=-2            # min pixel offset
MAX_MOVE=2             # max pixel offset
MIN_DELAY=1.15          # min delay (seconds)
MAX_DELAY=1.8          # max delay
MAX_DRIFT=6           # max distance before reset
# Timer config (seconds)
MIN_RUNTIME=$((15 * 60))  # 15 minutes
MAX_RUNTIME=$((30 * 60))  # 30 minutes

read -r START_X START_Y <<< "$(xdotool getmouselocation --shell | awk -F= '/X=|Y=/ {print $2}')"

random_offset() {
    awk -v min=$1 -v max=$2 'BEGIN { srand(); print int(min + rand() * (max - min + 1)) }'
}

random_delay() {
    awk -v min=$1 -v max=$2 'BEGIN { srand(); print min + rand() * (max - min) }'
}

random_runtime() {
    awk -v min=$1 -v max=$2 'BEGIN { srand(); print int(min + rand() * (max - min + 1)) }'
}

distance_between() {
    local x1=$1
    local y1=$2
    local x2=$3
    local y2=$4
    awk -v x1="$x1" -v y1="$y1" -v x2="$x2" -v y2="$y2" \
        'BEGIN { dx = x2 - x1; dy = y2 - y1; print sqrt(dx*dx + dy*dy) }'
}

# Pick random run time in seconds
RUN_TIME=$(random_runtime $MIN_RUNTIME $MAX_RUNTIME)
START_TIME=$(date +%s)

while true; do
    CURRENT_TIME=$(date +%s)
    ELAPSED=$((CURRENT_TIME - START_TIME))

    if [ "$ELAPSED" -ge "$RUN_TIME" ]; then
        echo "Reached max runtime of $RUN_TIME seconds, exiting."
        exit 0
    fi

    CHANCE=$(awk 'BEGIN { srand(); print int(1 + rand() * 100) }')

    if [ "$CHANCE" -le "$PROB_MOVE" ]; then
        X_OFFSET=$(random_offset $MIN_MOVE $MAX_MOVE)
        Y_OFFSET=$(random_offset $MIN_MOVE $MAX_MOVE)
        xdotool mousemove_relative -- "$X_OFFSET" "$Y_OFFSET"
    fi

    read -r CUR_X CUR_Y <<< "$(xdotool getmouselocation --shell | awk -F= '/X=|Y=/ {print $2}')"
    DIST=$(distance_between "$START_X" "$START_Y" "$CUR_X" "$CUR_Y")
    DIST_INT=${DIST%.*}

    if [ "$DIST_INT" -gt "$MAX_DRIFT" ]; then
        xdotool mousemove "$START_X" "$START_Y"
    fi

    DELAY=$(random_delay $MIN_DELAY $MAX_DELAY)
    sleep "$DELAY"

    xdotool click 1
done