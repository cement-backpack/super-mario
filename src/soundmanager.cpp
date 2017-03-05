#include "soundmanager.h"

SoundManager::SoundManager() {
    al_reserve_samples(4);

    theme = al_load_sample("res/sounds/themes/overworld.ogg");
    jump_small = al_load_sample("res/sounds/sounds/jump-small.ogg");
    jump_big = al_load_sample("res/sounds/sounds/jump-big.ogg");
    die = al_load_sample("res/sounds/sounds/die.ogg");
}

void SoundManager::playTheme() {
    al_play_sample(theme, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, &themeID);
}

void SoundManager::playJumpSmall() {
    al_play_sample(jump_small, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void SoundManager::playJumpBig() {
    al_play_sample(jump_big, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void SoundManager::PlayPlayerDie() {
    al_stop_sample(&themeID);
    al_play_sample(die, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
}
