import pygame
import sys
import random

#initialize Pygame
pygame.init()

#Gmae constant and variable
SCREEN_WIDTH = 700
SCREEN_HEIGHT = 600
GRAVITY = 0.25
BIRD_JUMP = -6
PIPE_SPEED = 3
GAP_SIZE = 150

#Colour
WHITE = (255,255,255)
BLUE = (135,306,235)
GREEN = (0,255,0)
YELLOW = (255,255,0)

#Setup Screen
screen = pygame.display.set_mode((SCREEN_WIDTH,SCREEN_HEIGHT))
clock = pygame.time.Clock()

#Bird detup
bird_rect = pygame.Rect(50,SCREEN_HEIGHT // 2,30,30)
bird_movement = 0

#pipe setup
pipe = []
SPAWNPIPE = pygame.USEREVENT
pygame.time.set_timer(SPAWNPIPE,1200)

def create_pipe():
	random_pipe_pos = random.randint(150,450)
	bottom_pipe = pygame.Rect(SCREEN_WIDTH,random_pipe_pos,50,SCREEN_HEIGHT)
	top_pipe = pygame.Rect(SCREEN_WIDTH,random_pipe_pos - GAP_SIZE - SCREEN_HEIGHT,50,SCREEN_HEIGHT)
	return bottom_pipe, top_pipe

def mpve_pipes(pipes_list):
	for pipe in pipes_list:
		pipe.centerx -= PIPE_SPEED
	return [pipe for pipe in pipes_list if pipe.right >- 50]

def draw_pipes(pipes_list):
	for pipe in pipe_list:
		pygame.draw.rect(screen,GREEN,pipe)

def check_collision(pipes_list):
	for pipe in pipes_list:
		if bird_rect.colliderext(pipe):
			return False
	if bird_rect.top <= 0 or bird_rect.bottom >= SCREEN_HEIGHT:
		return False
	return True

#Main Game Loop
while True: 
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			pygame.quit()
			sys.exit()
	#tap screen or press key to jump
	if event.type == pygame.KEYDOWN or event.type == pygame.MOUSEBUTTONDOWN:
		bird_movement = 0
		bird_movement += BIRD_JUMP

	if event.type == SPAWNPIPE: 
		pipes.extend(create_pipe())
	
	#game logic
	screen.fill(BLUE)

	#bird physic
	bird_movement += GRAVITY
	bird_rect_centery += bird_movement
	pygame.draw.ellipse(screen,YELLOW,bird_rect)

	#pipe logic
	pipes = move_pipes(pipes)
	draw_pipes(pipes)

	#collision
	if not check_collision(pipes):
		bird_rect.center - (50,SCREEN_HEIGHT // 2)
		bird_movement = 0
		pipes.clear()

	pygame.display.update()
	clocktick(60) #60fps
