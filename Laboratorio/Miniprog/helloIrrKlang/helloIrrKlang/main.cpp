//
//  main.cpp
//  helloIrrKlang
//
//  Created by Luis Ernesto Ochoa Rios on 10/3/19.
//  Copyright © 2019 Luis Ernesto Ochoa Rios. All rights reserved.
//

#include <iostream>
#include "irrKlang.h"

using namespace irrklang;


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Path is: %s", argv[0]);
    
    
    //start the sound engine with default parameters
    ISoundEngine* engine = createIrrKlangDevice();
    
    if (!engine){
        std::cout << "Could not startup engine. \n";
        return 0;
    }
    
    // To play a sound, we only to call play2D(). The second parameter
    // tells the engine to play it looped.
    
    // Play some sound stream, looped
    engine->play2D("WiiShopChannel.wav",true);
    
    // In a loop, wait until user presses 'q' to exit or another key to
    // play another sound.
    std::cout << "Hello, World!\n";
    
    do {
        std::cout << "Press any key to play some sound, press 'q' to quit.\n";
        //play a single sound
        
        engine->play2D("bell.wav");
        
    }
    while(getchar() != 'q');
    
    // After we are finished, we have to delete the irrKlang Device created earlier
    // with createIrrKlangDevice(). Use ::drop() to do that.
    
    engine->drop(); //Delete's engine
    return 0;
    
    
}
