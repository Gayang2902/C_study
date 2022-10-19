from textwrap import fill
import pygame
background = pygame.image.load("/Users/kd_mb/Desktop/code/Python/Pygame/Pang Game/game image/background.png")
screen = pygame.display.set_mode((640, 480))
running = True
time = pygame.time.Clock()
while(running):
    dt = time.tick(30)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    background.blit(background, (0, 0))
    
    pygame.display.update()
    