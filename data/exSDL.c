
#include <SDL/SDL.h>

/*
 compilation soous Linux : gcc -o exSDL exSDL.c -lSDL
 compilation sur Mac : gcc -o exSDL -I/Library/Frameworks/SDL.framework/Headers  exSDL.c SDLmain.m -framework SDL -framework Cocoa
*/

int autoDraw=0;

// px, py coordonnées haut, gauche de la texture
void drawTexture(SDL_Surface *ecran, int px, int py, SDL_Surface *ima) {
	SDL_Rect rect;
    rect.x=px;
    rect.y=py;
	SDL_BlitSurface(ima, NULL, ecran, &rect);
	SDL_Flip(ecran);
}

// px, py coordonnées haut, gauche du pixel
void drawRectangle(SDL_Surface *ecran, int px, int py, int size, int r, int g, int b) {
    SDL_Rect rect;
    rect.x=px;
    rect.y=py;
    rect.h=rect.w=size;
    SDL_FillRect(ecran, &rect, SDL_MapRGB(ecran->format, r, g, b));
    SDL_Flip(ecran);
}

// px, py coordonnées haut, gauche du pixel
void drawPixel(SDL_Surface *ecran, int px, int py, int r, int g, int b) {
    drawRectangle(ecran,  px,  py, 1,  r,  g,  b);
}

void fillScreen(SDL_Surface *ecran, int r, int g, int b) {
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, r, g, b));
    SDL_Flip(ecran);
}

int main(int argc, char *argv[]) {
	int continuer = 1;
	SDL_Surface *ecran = NULL;
	SDL_Event event;
    const SDL_VideoInfo* info = NULL;
    SDL_Surface *ima=NULL;
    
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        /* Failed, exit. */
        fprintf( stderr, "Video initialization failed: %s\n", SDL_GetError( ) );
        SDL_Quit( );
    }
    info = SDL_GetVideoInfo( );
    if( !info ) {
        /* This should probably never happen. */
        fprintf( stderr, "Video query failed: %s\n", SDL_GetError( ) );
        SDL_Quit( );
    }
    
	ecran=SDL_SetVideoMode(500, 500, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("exemple SDL", NULL);

    ima = SDL_LoadBMP("./cerise.bmp");
	
    
    fillScreen(ecran, 0,0,0);
    drawRectangle(ecran, 250, 250, 5, 0, 255, 255);
    
    while (continuer) {
        SDL_WaitEvent(&event);
        switch(event.type) {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
            	switch (event.key.keysym.sym) {
            		case SDLK_p:
                        drawRectangle(ecran, 250, 250, 2, 255, 255, 255);
                        drawRectangle(ecran, 0, 0, 10, 255, 0, 0);
                        drawPixel(ecran, 1, 1, 0, 255, 0);
                        drawPixel(ecran, 0, 0, 0, 0, 255);

                        break;
            		case SDLK_e:
                        fillScreen(ecran, 255,0,255);
						break;
                    case SDLK_r:
                        fillScreen(ecran, 0,0,0);
                        break;
                    case SDLK_t :
                        drawTexture(ecran, 100, 150, ima);
                        break;
            		case SDLK_ESCAPE:
						continuer=0; break;
            	}
            	break;
                
            case SDL_MOUSEBUTTONUP:
                autoDraw=0;
                if (event.button.button == SDL_BUTTON_LEFT) {
                    drawRectangle(ecran, event.button.x, event.button.y, 3, 255, 0, 0);
                }
                               break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    autoDraw=1;
                    drawRectangle(ecran, event.button.x, event.button.y, 3, 0, 255, 0);
                }
                else if(event.button.button == SDL_BUTTON_RIGHT)
                {
                    int x,y;
                    x = event.button.x ;
                    y = event.button.y ;
                    int bpp = ecran->format->BytesPerPixel;
                    /* Here p is the address to the pixel we want to retrieve */
                    Uint8 *p = (Uint8 *)ecran->pixels + y * ecran->pitch + x * bpp;
                    fprintf(stderr,"%d %d -> %d %d %d\n",y, x, p[0], p[1], p[2]);
                }
                break;
            case SDL_MOUSEMOTION:
                if (autoDraw)
                    drawRectangle(ecran, event.button.x, event.button.y, 1, 0, 0, 255);
                
                break;

                
                
        }
    }
	SDL_Quit();
    
	return 0;
}
