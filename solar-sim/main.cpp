#include <iostream>

#include "display.h"
#include "body.h"
#include "universe.h"

int main() {

    display::WorldSize = 150.0; // 500.0;
    display::RecordDuration = 300;
    display::VideoFile = "video.avi";
    display::ScreenWidth = 1920;
    display::ScreenHeight = 1080;

    body::GravityConstant = 0.5;
    body::Seed = 2.99281; //1.22498;
    body::TimeStep = 0.01;
    body::Mass = 100.0;
    body::CollisionRadius = 0.8;
    body::TerminalAcceleration = 400.0;
    body::SpeedRange = 5.0;
    universe::MassDistribution = universe::DistributionType::D_ROTATING_SPHERICAL;
    universe::NumBodies = 25000;
    universe::SpreadRadius = 200.0;

    display::init();
    universe::init();

    while (!display::quit()) {
        display::clear();
        universe::render();
        universe::update();
        display::update();
    }

    display::exit();

    return 0;
}
