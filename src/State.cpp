#include "State.h"

State::State(){
    quitRequested = false;
	GameObject *bg;
	bg = new GameObject();
	Sprite *fundo = new Sprite("assets/img/ocean.jpg", *bg);
	bg->box.CSEx = (float)0;
	bg->box.CSEy = (float)0;
	bg->box.Larg = (float)fundo->GetLargura();
	bg->box.Alt = (float)fundo->GetAltura();	
	Sound *musica = new Sound("assets/audio/stageState.ogg", *bg);
	bg->AddComponent(fundo);
	bg->AddComponent(musica);
	objectArray.emplace_back(bg);
}

State::~State(){
	objectArray.clear();
}

bool State::QuitRequested(){
    return quitRequested;
}

void State::LoadAssets(){

}

void State::Update(float dt){
	Input();
	std::vector<int> mortos;
	for(unsigned int i=0; i<objectArray.size(); i++){
		objectArray[i]->Update(dt);
		if (objectArray[i]->IsDead()){
            mortos.push_back(i); 
        } 
	}
	while (!mortos.empty()){
		objectArray.erase(objectArray.begin() + mortos.back());
		mortos.pop_back();
	}	
}

void State::Render(){
	for(unsigned int i=0; i<objectArray.size(); i++){
		objectArray[i]->Render();
	}
}

void State::AddObject(int posX, int posY){
	GameObject *inimigo;
	inimigo = new GameObject();
	Sprite *faceta = new Sprite("assets/img/penguinface.png", *inimigo);
	inimigo->box.CSEx = (float)posX;
	inimigo->box.CSEy = (float)posY;
	inimigo->box.Larg = (float)faceta->GetLargura();
	inimigo->box.Alt = (float)faceta->GetAltura();
	Sound *barulho = new Sound("assets/audio/boom.wav", *inimigo);
	Face *face = new Face(*inimigo);
	inimigo->AddComponent(faceta);
	inimigo->AddComponent(barulho);
	inimigo->AddComponent(face);
	objectArray.emplace_back(inimigo);
}

void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT) {
			quitRequested = true;
		}
		
		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if(go->box.EstaDentro((float)mouseX, (float)mouseY) ) {
					Face* face = (Face*)go->GetComponent( "Face" );
					if ( nullptr != face ) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
		}
		if( event.type == SDL_KEYDOWN ) {
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE ) {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				Vet2 objPos = Vet2(200, 0).Rotacao(-M_PI + M_PI*(rand() % 1001)/500.0 ) + Vet2(mouseX, mouseY);
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}