import curses
import random
import time

# Setup the window
stdscr = curses.initscr()
curses.curs_set(0)
h, w = 20, 60  # height and width of window
win = curses.newwin(h, w, 0, 0)
win.keypad(1)
win.timeout(100)  # Refresh every 100ms

# Initial snake and food setup
snk_x = w // 4
snk_y = h // 2
snake = [
    [snk_y, snk_x],
    [snk_y, snk_x - 1],
    [snk_y, snk_x - 2]
]
food = [random.randint(1, h - 2), random.randint(1, w - 2)]
win.addch(food[0], food[1], 'F')

# Initial direction
key = curses.KEY_RIGHT
score = 0

while True:
    win.border(0)
    win.addstr(0, 2, f'Score: {score} ')

    next_key = win.getch()
    key = key if next_key == -1 else next_key

    # Calculate new head
    head = snake[0][:]
    if key == curses.KEY_DOWN:
        head[0] += 1
    elif key == curses.KEY_UP:
        head[0] -= 1
    elif key == curses.KEY_LEFT:
        head[1] -= 1
    elif key == curses.KEY_RIGHT:
        head[1] += 1

    # Game over conditions
    if (head in snake) or (head[0] in [0, h - 1]) or (head[1] in [0, w - 1]):
        break

    # Insert new head
    snake.insert(0, head)

    # Check food collision
    if head == food:
        score += 10
        food = None
        while food is None:
            nf = [random.randint(1, h - 2), random.randint(1, w - 2)]
            if nf not in snake:
                food = nf
        win.addch(food[0], food[1], 'F')
    else:
        # Move forward (remove tail)
        tail = snake.pop()
        win.addch(tail[0], tail[1], ' ')

    win.addch(head[0], head[1], 'O')

# End game
curses.endwin()
print(f"Game Over! Your score: {score}")
