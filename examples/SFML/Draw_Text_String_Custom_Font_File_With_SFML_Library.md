# Draw Text String Custom Font File With SFML Library
i just code with ttf file.

```c++
sf::Font font_stratum;
font_stratum.loadFromFile("C:/Users/Amiral/source/repos/CsGoSFML/Debug/fonts/stratum2bold.ttf");

sf::Color color_yellow_nople = sf::Color::Color(255, 255, 0, 220);
sf::Color color_black_alpha = sf::Color::Color(0, 0, 0, 150);

sf::Text text_player_name;
text_player_name.setFont(font_stratum);
text_player_name.setCharacterSize(14);
text_player_name.setColor(color_yellow_nople);
text_player_name.setOutlineColor(color_black_alpha);
text_player_name.setOutlineThickness(1);

window.draw(text_player_name);
```
