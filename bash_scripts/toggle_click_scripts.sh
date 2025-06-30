#!/bin/bash
# Simple script for starting and stopping a program based on a PID file

PID_FILE="$HOME/.local/share/random_clicker.pid"
SCRIPT_FILE="$HOME/Documents/ran_click_script.sh"

if [ -f "$PID_FILE" ]; then
    echo "Stopping clicker..."
    kill "$(cat "$PID_FILE")" && rm "$PID_FILE"
else
    echo "Starting clicker..."
    nohup bash "$SCRIPT_FILE" >/dev/null 2>&1 &
    echo $! > "$PID_FILE"
fi
