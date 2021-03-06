#include "TileMap.h"

TileMap::TileMap(GameObject &associated, std::string file, TileSet *tileset) : Component(associated) {
    Load(file);
    SetTileSet(tileset); 
}

void TileMap::Load(std::string file){
    char line[256];
    char *valor;
    FILE *mapa = fopen(file.c_str(),"r"); 
    if (mapa == NULL)
        printf("Falha da abertura do TileMap");
    else{
        while(fgets(line, sizeof(line), mapa)){
            valor = strtok(line, " ,\n");
            if (valor != NULL){
                int num = atoi(valor);
                tileMatrix.emplace_back(num-1);
            }
            while (valor != NULL){
                valor = strtok(NULL, " ,\n");
                if (valor != NULL){
                    int sla = atoi(valor);
                    tileMatrix.emplace_back(sla-1);
                }
            }
        }
        fclose(mapa);
    }
    mapLargura = tileMatrix[0]+1;
    mapAltura = tileMatrix[1]+1;
    mapProfundidade = tileMatrix[2]+1;
    tileMatrix.erase(tileMatrix.begin(),tileMatrix.begin()+3);
}

void TileMap::SetTileSet(TileSet *tileset){
    this->tileSet = tileset;
}

int &TileMap::At(int x, int y, int z){
    int index = (x-1)*mapLargura + y - 1;
    return tileMatrix[index];
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY){
    int inicio = mapLargura*mapAltura*(layer-1);
    int fim = mapLargura*mapAltura*layer;
    int x = cameraX, y = cameraY;
    for(int i=inicio; i<fim; i++){ 
        tileSet->RenderTile(tileMatrix[i],(float)x,(float)y);
        x += tileSet->GetTileLargura();
        if ((i+1)%mapLargura == 0){
            y += tileSet->GetTileAltura();
            x = cameraX;
        }
    }
}

void TileMap::Render(){
    for (int i=1; i <= GetProfundidade(); i++ )
        RenderLayer(i, Camera::pos.x, Camera::pos.y);
}

void TileMap::Update(float dt){

}

bool TileMap::Is(std::string type){
    if (type == "Mapa")
        return true;
    else 
        return false;
}

int TileMap::GetLargura(){
    return mapLargura;
}

int TileMap::GetAltura(){
    return mapAltura;
}

int TileMap::GetProfundidade(){
    return mapProfundidade;
}
