#include "TileSet.h"

TileSet::TileSet(int tileLargura, int tileAltura, std::string file){
    this->tileLargura = tileLargura;
    this->tileAltura = tileAltura;
    tileSet.Open(file);
    if(tileSet.IsOpen()){
        colunas = tileSet.GetLargura()/tileLargura;
        linhas = tileSet.GetAltura()/tileAltura;
    }
    else{
        printf("Problema na abertura do TileSet");
    }
}

void TileSet::RenderTile(unsigned index, float x, float y){
    if((int)index >= 0 && (int)index <= (colunas*linhas - 1)){
        int posY = (index/colunas)*64;
        int posX = (index%colunas)*64;
        //printf("PosX: %d e PosY: %d\n\n",posX, posY);
        tileSet.SetClip(posX, posY, tileLargura, tileAltura);
        tileSet.Render(x,y);
    }
    else{
        //printf("Indice fora da imagem\n");
    }
}

int TileSet::GetTileLargura(){
    return tileLargura;
}

int TileSet::GetTileAltura(){
    return tileAltura;
}