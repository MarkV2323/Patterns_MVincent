# Singleton Pattern

The **Singleton Pattern** ensures that **only one instance** of a class exists throughout the program **and provides a global point of access** to it.

**NOTE** - Thread safety can become important for singletons, do not forget about it!

This is useful when exactly **one object is needed** to coordinate actions across a system — think configuration managers, logging systems, or resource managers.

* Singleton is useful for **global coordination**, like logging or configuration.
* But it’s often **overused**, and can make code **tightly coupled** and **hard to test**.
* In Python, due to its dynamic nature, simpler approaches (like using a module itself) can often replace a singleton cleanly.

Some good use cases may be,
* **Logger** - Centralized, global access; no need to create multiple loggers.
* **Configuration Manager** - Prevents re-parsing config files and ensures consistency.
* **Database Connection Pool / Drive**r - Connection setup is expensive; prevents resource exhaustion.
* **Thread Pool / Executor** -  Central control of threading; avoids spawning uncontrolled threads.
* **Application State** - Single source of truth for application-wide state.

| Advantage               | Explanation                                                        |
| ----------------------- | ------------------------------------------------------------------ |
| **Controlled Access**   | Ensures a single point of access to a resource (e.g., logger, DB). |
| **Global State**        | Makes shared data accessible throughout the app.                   |
| **Lazy Initialization** | You can create the instance only when needed.                      |

---

| Disadvantage            | Explanation                                                                 |
| ----------------------- | --------------------------------------------------------------------------- |
| **Global State**        | Can hide dependencies and make code harder to test.                         |
| **Difficult to Test**   | Mocking or resetting singletons in tests can be tricky.                     |
| **Hidden Dependencies** | Classes depending on singletons don’t show that clearly in their interface. |
| **Concurrency Issues**  | In multi-threaded programs, extra care is needed to avoid race conditions.  |
