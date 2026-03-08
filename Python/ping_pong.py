import turtle
import time


win = turtle.Screen()
win.title("Ping Pong")
win.bgcolor("black")
win.setup(width=800, height=600)
win.tracer(0)


score_a = 0
score_b = 0
game_running = True
game_paused = False

keys = {"w": False, "s": False, "Up": False, "Down": False}

def key_press(k):
    keys[k] = True

def key_release(k):
    keys[k] = False


pen = turtle.Turtle()
pen.speed(0)
pen.color("white")
pen.penup()
pen.hideturtle()
pen.goto(0, 260)
pen.write("Player A: 0  Player B: 0", align="center", font=("Courier", 20, "normal"))


divider = turtle.Turtle()
divider.speed(0)
divider.color("grey")
divider.penup()
divider.hideturtle()
for y in range(-280, 290, 25):
    divider.goto(0, y)
    divider.pendown()
    divider.goto(0, y + 12)
    divider.penup()


paddle_a = turtle.Turtle()
paddle_a.speed(0)
paddle_a.shape("square")
paddle_a.color("cyan")
paddle_a.shapesize(stretch_wid=5, stretch_len=1)
paddle_a.penup()
paddle_a.goto(-350, 0)

paddle_b = turtle.Turtle()
paddle_b.speed(0)
paddle_b.shape("square")
paddle_b.color("red")
paddle_b.shapesize(stretch_wid=5, stretch_len=1)
paddle_b.penup()
paddle_b.goto(350, 0)


ball = turtle.Turtle()
ball.speed(0)
ball.shape("circle")
ball.color("yellow")
ball.penup()
ball.goto(0, 0)
ball.dx = 2.5
ball.dy = 2.5


overlay = turtle.Turtle()
overlay.speed(0)
overlay.color("white")
overlay.penup()
overlay.hideturtle()

btn = turtle.Turtle()
btn.speed(0)
btn.penup()
btn.hideturtle()

def draw_restart_button():
    btn.goto(0, -80)
    btn.color("white")
    btn.shape("square")
    btn.shapesize(stretch_wid=1.8, stretch_len=5)
    btn.showturtle()
    overlay.goto(0, -92)
    overlay.color("black")
    overlay.write("▶  RESTART", align="center", font=("Courier", 16, "bold"))

def hide_restart_button():
    btn.hideturtle()

def update_score():
    pen.clear()
    pen.write(
        f"Player A: {score_a}  Player B: {score_b}",
        align="center",
        font=("Courier", 20, "normal")
    )

def reset_ball(direction):
    ball.goto(0, 0)
    ball.dx = 2.5 * direction
    ball.dy = 2.5

def show_winner():
    overlay.clear()
    overlay.goto(0, 60)
    overlay.color("yellow")
    winner = "Player A (Cyan)" if score_a > score_b else "Player B (Red)"
    overlay.write(f"🏆  {winner} Wins!", align="center", font=("Courier", 26, "bold"))
    overlay.goto(0, 10)
    overlay.color("white")
    overlay.write(f"Final Score  —  A: {score_a}  |  B: {score_b}", align="center", font=("Courier", 16, "normal"))
    draw_restart_button()

def show_paused():
    overlay.clear()
    overlay.goto(0, 30)
    overlay.color("orange")
    overlay.write("⏸  PAUSED", align="center", font=("Courier", 28, "bold"))
    overlay.goto(0, -20)
    overlay.color("white")
    overlay.write("Press  SPACE  to resume", align="center", font=("Courier", 14, "normal"))

def hide_overlay():
    overlay.clear()
    hide_restart_button()

def restart_game():
    global score_a, score_b, game_running, game_paused
    score_a = 0
    score_b = 0
    game_running = True
    game_paused = False
    hide_overlay()
    update_score()
    paddle_a.goto(-350, 0)
    paddle_b.goto(350, 0)
    reset_ball(1)

def toggle_pause():
    global game_paused, game_running
    if not game_running:
        return
    if game_paused:
        game_paused = False
        hide_overlay()
    else:
        game_paused = True
        show_paused()

def handle_click(x, y):
    if btn.isvisible() and -50 < x < 50 and -100 < y < -60:
        restart_game()

win.listen()
for k in keys:
    win.onkeypress(lambda key=k: key_press(key), k)
    win.onkeyrelease(lambda key=k: key_release(key), k)

win.onkeypress(toggle_pause, "space")
win.onclick(handle_click)

PADDLE_SPEED = 8
BALL_SPEED_INCREMENT = 0.15
MAX_BALL_SPEED = 7
running = True

def on_close():
    global running
    running = False

win.getcanvas().winfo_toplevel().protocol("WM_DELETE_WINDOW", on_close)

while running:
    try:
        time.sleep(0.01)
        win.update()

        if game_paused or not game_running:
            continue

        if keys["w"] and paddle_a.ycor() < 250:
            paddle_a.sety(paddle_a.ycor() + PADDLE_SPEED)
        if keys["s"] and paddle_a.ycor() > -250:
            paddle_a.sety(paddle_a.ycor() - PADDLE_SPEED)
        if keys["Up"] and paddle_b.ycor() < 250:
            paddle_b.sety(paddle_b.ycor() + PADDLE_SPEED)
        if keys["Down"] and paddle_b.ycor() > -250:
            paddle_b.sety(paddle_b.ycor() - PADDLE_SPEED)

        ball.setx(ball.xcor() + ball.dx)
        ball.sety(ball.ycor() + ball.dy)

        if ball.ycor() > 285:
            ball.sety(285)
            ball.dy *= -1
        if ball.ycor() < -285:
            ball.sety(-285)
            ball.dy *= -1

        if ball.xcor() > 395:
            score_a += 1
            update_score()
            if score_a >= 5:
                game_running = False
                ball.goto(0, 0)
                ball.dx = 0
                ball.dy = 0
                show_winner()
            else:
                reset_ball(-1)

        if ball.xcor() < -395:
            score_b += 1
            update_score()
            if score_b >= 5:
                game_running = False
                ball.goto(0, 0)
                ball.dx = 0
                ball.dy = 0
                show_winner()
            else:
                reset_ball(1)

        if (330 < ball.xcor() < 355) and (paddle_b.ycor() - 55 < ball.ycor() < paddle_b.ycor() + 55):
            ball.setx(329)
            speed = abs(ball.dx) + BALL_SPEED_INCREMENT
            ball.dx = -min(speed, MAX_BALL_SPEED)

        if (-355 < ball.xcor() < -330) and (paddle_a.ycor() - 55 < ball.ycor() < paddle_a.ycor() + 55):
            ball.setx(-329)
            speed = abs(ball.dx) + BALL_SPEED_INCREMENT
            ball.dx = min(speed, MAX_BALL_SPEED)
    except Exception:
        break

turtle.bye()