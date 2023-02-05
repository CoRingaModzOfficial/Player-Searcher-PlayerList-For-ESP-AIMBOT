## ESP LIST ENEMY




1 [Player Seacher]


//UPDATE OFFSET USE
void (*old_Player_update)(...);
void Player_update(void *player) {
    if (player != NULL) {
        
        if (!playerFind(player)) players.push_back(player);
        if (players.size() > 15) {
            players.clear();
        }
    }
    clearPlayers();
    old_Player_update(player);
}
///END UPDATE


vector<void*> players;

void clearPlayers() {
    vector<void*> pls;
    for (int i = 0; i < players.size(); i++) {
        if (players[i] != NULL) {
            pls.push_back(players[i]);
        }
    }
    players = pls;
}

bool playerFind(void *pl) {
    if (pl != NULL) {
        for (int i = 0; i < players.size(); i++) {
            if (pl == players[i]) return true;
        }
    }
    return false;
}



//ADD FOR GET LIST
for (int i = 0; i < players.size(); i++) {
       
        void *ObteLista;   
        
        if (i < players.size()) ObteLista = players[i];


//END Get List




[End]




2 [ESP MANAGER]



///ESP MANAGER.H

Create File .h
Name : EspManager.h


void *myPlayer = NULL;
struct enemy_t {
    void *object;
    Vector3 location;
    int health;
};

class ESPManager {
public:
    std::vector<enemy_t *> *enemies;

    ESPManager() {
        enemies = new std::vector<enemy_t *>();
    }

    bool isEnemyPresent(void *enemyObject) {
        for (std::vector<enemy_t *>::iterator it = enemies->begin(); it != enemies->end(); it++) {
            if ((*it)->object == enemyObject) {
                return true;
            }
        }
        return false;
    }

    void removeEnemy(enemy_t *enemy) {
        for (int i = 0; i < enemies->size(); i++) {
            if ((*enemies)[i] == enemy) {
                enemies->erase(enemies->begin() + i);
                return;
            }
        }
    }

    void tryAddEnemy(void *enemyObject) {
        if (isEnemyPresent(enemyObject)) {
        return;
        }

        enemy_t *newEnemy = new enemy_t();

        newEnemy->object = enemyObject;

        enemies->push_back(newEnemy);
    }

    void updateEnemies(void *enemyObject) {
        for (int i = 0; i < enemies->size(); i++) {
            enemy_t *current = (*enemies)[i];                 
        }
    }

    void removeEnemyGivenObject(void *enemyObject) {
        for (int i = 0; i < enemies->size(); i++) {
            if ((*enemies)[i]->object == enemyObject) {
                enemies->erase(enemies->begin() + i);
                return;
            }
        }
    }
};
//END ESP MANAGER.H



///UPDATE OFFSET USE
void *enemyPlayer = NULL;
void *updatePlayer = NULL;

void (*old_Player_update)(...);
void Player_update(void *player) {
    if (player != NULL) {
        
        old_Player_update(player);
        updatePlayer = player;
              enemyPlayer = player;    

        if (Esp) {              
                if (enemyPlayer) {             
                        espManager->tryAddEnemy(player);             
                }
                espManager->updateEnemies(player);
            }
        }
    }
//esp Manager Update end


//ADD FOR GET LIST
for (int i = 0; i < espManager->enemies->size(); i++) {
        void *ObteListadosPlayers = (*espManager->enemies)[i]->object;
//[end]



