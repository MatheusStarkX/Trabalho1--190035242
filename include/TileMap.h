#ifndef TILEMAP_H
#define TILEMAP_H

#include "GameObject.h"
#include "TileSet.h"
#include "Camera.h"

#include <string>

class TileMap : public Component {
    private:
        std::vector<int> tileMatrix;
        TileSet *tileSet;
        int mapLargura;
        int mapAltura;
        int mapProfundidade;
    public:
        TileMap(GameObject &associated, std::string file, TileSet *tileset);
        void Load(std::string file);
        void SetTileSet(TileSet *tileset);
        int &At(int x, int y, int z=0);
        void Render();
        void RenderLayer(int layer, int cameraX=0, int cameraY=0);
        void Update(float dt);
        bool Is(std::string type);
        int GetAltura();
        int GetLargura();
        int GetProfundidade();     
};

#endif