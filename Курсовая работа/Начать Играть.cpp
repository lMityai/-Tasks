#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <windows.h>

using namespace sf;

int main() {

    HWND hConsole = GetConsoleWindow(); 
    ShowWindow(hConsole, SW_HIDE); 

    RenderWindow window(VideoMode(346, 122), "Tetris Launcher");

    Image start;
    start.loadFromFile("knopka.png"); 

    Texture starttexture; 
    starttexture.loadFromImage(start); 

    Sprite startsprite;
    startsprite.setTexture(starttexture); 
    startsprite.setPosition(20, 20); 

    while (window.isOpen()) {

		
		Vector2i pos = Mouse::getPosition(window);
		int x = pos.x;
		int y = pos.y;
        
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed)
                if (event.key.code == Mouse::Left) {
                    if (x >= 20 && x <= 326 && y >= 20 && y <= 102) {
                        system("start Tetris/x64/Debug/Tetris.exe");
                        window.close();
                    } 
                }
        }

        window.clear();
        window.draw(startsprite); 
        window.display();
    }

    return 0;
}
