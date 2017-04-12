#include "BiRelKin.h"

int main() {
    
    ////////////////////////////////
    //  Particle 0: Projectile
    //  Particle 1: Target
    //  Particle 2: Ejectile
    //  Particle 3: Recoil
    
    Double_t m[4];
    Double_t T[4];
    Double_t E[4];
    Double_t p[4];
    
    ////    Excitation of the Recoil Nucleus
    Double_t Ex; // MeV
    
    ////    ThSCAT_ejectile is the angle of the Ejectile with respect to the beam axis
    Double_t ThSCAT_ejectile; // deg
    
    ////    ThSCAT_recoil is the angle of the Recoil with respect to the beam axis
    Double_t ThSCAT_recoil; // deg

    for(Int_t i=0; i<4; i++)
    {
        m[i] = 0.0;
        T[i] = 0.0;
        E[i] = 0.0;
        p[i] = 0.0;
    }
    

    ////    These are the input variables
    m[0] = 4;
    m[1] = 16;
    m[2] = 4;
    m[3] = 16;
    
    ////    Projectile/Beam Energy (Lab Frame)
    T[0] = 200.0;
    
    ////    Target Energy (Lab Frame)
    T[1] = 0.0;


    ThSCAT_ejectile = 2.; // deg
    //Ex = 15.097; // MeV
    Ex = 12.000; // MeV
    BiRelKin(m, T, E, p, ThSCAT_ejectile, ThSCAT_recoil, Ex);
    
    
}



