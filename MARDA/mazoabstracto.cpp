#include "mazoabstracto.h"

MazoAbstracto::MazoAbstracto() {

}

MazoAbstracto::MazoAbstracto(vector<Carta>* cartas) : cartas(cartas) {

}

MazoAbstracto::~MazoAbstracto() {

}

void MazoAbstracto::barajarMazo() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->cartas->begin(), this->cartas->end(),
                 std::default_random_engine(seed));
}

Carta MazoAbstracto::sacarCartaMazo(int posicion) {
    Carta carta = this->cartas->at(posicion);
    this->cartas->erase(this->cartas->begin()+posicion);
    return carta;
}

vector<Carta>* MazoAbstracto::obtenerCartasMazo() {
    return this->cartas;
}

int MazoAbstracto::obtenerTamanioMazo() {
  return this->cartas->size();
}
