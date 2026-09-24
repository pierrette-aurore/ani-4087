#pragma once

#ifdef AVEC_CHRONO

class Chrono
{
public:
    void demarrer();
    void afficherDuree();
};

#else

class Chrono
{
};

#endif
