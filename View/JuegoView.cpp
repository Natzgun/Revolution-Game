#include "JuegoView.h"

JuegoView::JuegoView(std::queue<std::string> * coladeEventos_) :
  EstadoView(coladeEventos_){
}

void JuegoView::capturarEventos(sf::RenderWindow& window,sf::Event& evento) {
  while (window.pollEvent(evento)) {
    //Cuando se presionan
    if(evento.type == sf::Event::KeyPressed) {
      if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::W)
        coladeEventos->push("W_on");
      else if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::A)
        coladeEventos->push("A_on");
      else if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::S)
        coladeEventos->push("S_on");
      else if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::D)
        coladeEventos->push("D_on");
    }
    if(evento.type == sf::Event::MouseButtonPressed){
      if(evento.mouseButton.button == sf::Mouse::Left)
        coladeEventos->push("Lclick_on");
      else if(evento.mouseButton.button == sf::Mouse::Right)
        coladeEventos->push("Rclick_on");
    }
    //Cuando se dejan de presionar
    if(evento.type == sf::Event::KeyReleased) {
      if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::W)
        coladeEventos->push("W_off");
      else if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::A)
        coladeEventos->push("A_off");
      else if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::S)
        coladeEventos->push("S_off");
      else if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::D)
        coladeEventos->push("D_off");
    }
    if(evento.type == sf::Event::MouseButtonReleased){
      if(evento.mouseButton.button == sf::Mouse::Left)
        coladeEventos->push("Lclick_off");
      else if(evento.mouseButton.button == sf::Mouse::Right)
        coladeEventos->push("Rclick_off");
    }
  }
}
