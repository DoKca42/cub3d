import pygame
import sys
import math

pygame.init()
MAP_RES = 100

SCREEN_HEIGHT = MAP_RES * 10
SCREEN_WIDTH = MAP_RES * 6

win = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Raycast")

PI = 3.14159265

game_map = [
    '111111',
    '100011',
    '110001',
    '110001',
    '101001',
    '100101',
    '100001',
    '100N01',
    '101001',
    '111111'
]


hitbox = []
player = {'x': 3 * MAP_RES + MAP_RES / 2, 'y': 7 * MAP_RES + MAP_RES / 2, 'ray_x': 0, 'ray_y': 0, 'direc': 75}


def draw_rect(x, y, height, width, color):
    pygame.draw.rect(win, color, pygame.Rect(x, y, width, height))
    pygame.display.flip()

def draw_line(x1, y1, x2, y2, color):
    pygame.draw.line(win, color, (x1, y1), (x2, y2))
    pygame.display.flip()

def draw_circle(x, y, r, color):
    pygame.draw.circle(win, color, (x, y), r)

def grid():
    y = 0
    while y < 1000:
        draw_line(0, y, 600, y, (159, 159, 159))
        y += 100
    x = 0
    while x < 600:
        draw_line(x, 0, x, 1000, (159, 159, 159))
        x += 100

def disp_map():
    y = 0
    while y < 10:
        x = 0
        while x < 6:
            if game_map[y][x] == '1':
                hitbox.append({'x': x, 'y': y})
                draw_rect(x * MAP_RES, y * MAP_RES, MAP_RES, MAP_RES, (62, 222, 201))
            x += 1
        y += 1

def deg_to_rad(angle):
    rad = (angle * PI) / 180
    return (rad)

def get_case_player():
    case_x = int(player['x'] / MAP_RES)
    case_y = int(player['y'] / MAP_RES)
    case_x = case_x
    case_y = case_y
    return (case_x, case_y)

def cast_ray(x, y, angle):
    dx = get_case_player()[0] * MAP_RES - x
    dy = get_case_player()[1] * MAP_RES - y

    yn = dy
    xn = dy / math.tan(deg_to_rad(angle))

    print(xn, yn)
    draw_line(x, y, xn, yn, (25, 25, 25))

def player_up():
    x = player['x']
    y = player['y']
    player['direc'] = 75
    print(player)
    draw_circle(x, y, 10, (82, 222, 62))
    cast_ray(x, y, player['direc'])


draw_rect(0, 0, MAP_RES * 10, MAP_RES * 6, (255, 255, 255))
disp_map()
player_up()
grid()

while True:
    pygame.time.delay(10)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit(0)
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                player['x'] -= 4
            if event.key == pygame.K_RIGHT:
                player['x'] += 4
            if event.key == pygame.K_UP:
                player['y'] -= 4
            if event.key == pygame.K_DOWN:
                player['y'] += 4
            draw_rect(0, 0, MAP_RES * 10, MAP_RES * 6, (255, 255, 255))
            disp_map()
            player_up()
            grid()