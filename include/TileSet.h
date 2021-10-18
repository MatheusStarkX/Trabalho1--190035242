#ifndef TILESET_H
#define TILESET_H

#include "Sprite.h"
#include <string>

class TileSet {
    private:   
        Sprite tileSet;
        int linhas, colunas;
        int tileLargura, tileAltura;
    public:
        TileSet(int tileLargura, int tileAltura, std::string file);
        void RenderTile(unsigned index, float x, float y);
        int GetTileLargura();
        int GetTileAltura();
};

#endif