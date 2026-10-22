# Avaloka Assignment. Data Structures & Systems Design

## Overview

This repository holds my C++ solutions for the Data Structures & Systems Design take‑home assignment. The assignment belongs to the AI / Multi‑Agent Systems Intern role at Avaloka (Guruvai Sciences).

The assignment focuses on two tasks: an LRU Cache and an Event Scheduler. Both tasks require data structures and careful analysis of time and space complexity.

## Problem 1: LRU Cache Implementation

I built an LRU (Least Recently Used) Cache that uses a hash map and a linked list.

### Features

- `get(key)`: Returns the value linked to a key or `-1` when the key's missing.

- `put(key value)`: Adds a new key‑value pair or updates an existing one.

- When the cache reaches capacity it removes the least recently used entry.

- Both operations run in O(1) time.

### Data Structures

- `unordered_map` provides key lookup.

- `list` keeps track of the order in which items are used.

**Source file:** `lru_cache.cpp`

## Problem 2: Event Scheduler

I created an event scheduler that checks for overlapping events and determines the number of meeting rooms needed.

### Features

- `can_attend_all(events)`: Returns true if a person can attend every event without any overlap.

- `min_rooms_required(events)`: Calculates the number of meeting rooms needed.

- An event that ends at the time another starts is considered non‑overlapping.

### Data Structures and Algorithms

- Events are sorted by their start times.

- A min‑heap built with `priority_queue` tracks the end times of meetings.

**Source file:** `event_scheduler.cpp`

## How to Compile and Run

Install a C++ compiler such as GCC. Open a terminal in the project folder.

### Problem 1: LRU Cache

Compile:

```bash
g++ lru_cache.cpp -o lru_cache.exe
```

Run in Windows PowerShell:

```powershell
 .\lru_cache.exe
```

### Problem 2: Event Scheduler

Compile:

```bash

g++ event_scheduler.cpp -o event_scheduler.exe

```

Run in Windows PowerShell:

```powershell

.\event_scheduler.exe

```

## Complexity Analysis

### LRU Cache

- `get(key)`: O(1) time.

- `put(key value)`: O(1) time.

- Space usage is O(C) where C is the cache capacity.

### Event Scheduler

- `can_attend_all(events)`: O(n log n) time.

- `min_rooms_required(events)`: O(n log n) time.

- Space usage is O(n) in the case.

Here n represents the number of events.

## Final Discussion & Analysis

The final assignment document explains:

1. Time and space complexity in detail.

2. The reasoning behind pairing a hash map with a linked list in an LRU Cache.

3. The method, for assigning room numbers to scheduled events.

4. How to make the LRU Cache thread‑safe.

## Author

Bhaskar Sharma
