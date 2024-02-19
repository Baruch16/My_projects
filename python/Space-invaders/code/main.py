import pygame, sys
from player import Player
import obstacle
from alien import Alien, Extra
from random import choice, randint
from laser import Laser
from Functions import Functions



def run_game():
	pygame.init()
	clock = pygame.time.Clock()
	game = Functions()
	ALIENLASER = pygame.USEREVENT + 1
	pygame.time.set_timer(ALIENLASER,800)

	while True:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				pygame.quit()
				sys.exit()
			if event.type == ALIENLASER:
				game.alien_shoot()

		#game.screen.fill((game.bg_color))
		game.screen.blit(game.background,(0,0))
		game.run()
		
			
		pygame.display.flip()
		clock.tick(60)
		
if __name__ == '__main__':
	run_game()

