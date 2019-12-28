# Create SFML Overlay Transparent Window
Create a window as transparent background and ctopmost and unclickable window form.

```c++
sf::RenderWindow window;

sf::ContextSettings settings;
settings.antialiasingLevel = 8;


window.create(sf::VideoMode(screen_width, screen_height), "Amiral Router", sf::Style::None, settings);

window.setFramerateLimit(120); 

window.setVerticalSyncEnabled(false);

HWND hWnd = window.getSystemHandle();

SetWindowLong(hWnd, GWL_EXSTYLE, WS_EX_TRANSPARENT | WS_EX_LAYERED);
SetLayeredWindowAttributes(hWnd, 0, 255, LWA_ALPHA);

MARGINS margin = { -1 };
DwmExtendFrameIntoClientArea(hWnd, &margin);

::SetWindowPos(hWnd, HWND_TOPMOST, 1,1, screen_width, screen_height, SWP_SHOWWINDOW);
UpdateWindow(hWnd);
```
