#include <chrono>
#include <cmath>
#include <iostream>

int main()
{
    const int nbImages = 30;
    const int nbIterations = 400000;

    double sommeTemps = 0.0;
    double accumulateur = 0.0;

    for (int image = 0; image < nbImages; ++image)
    {
        auto debut = std::chrono::steady_clock::now();

        for (int i = 0; i < nbIterations; ++i)
        {
            double angle = i * 0.00002;
            accumulateur += std::sqrt(std::fabs(std::sin(angle) * std::tan(angle * 0.5)));
        }

        auto fin = std::chrono::steady_clock::now();
        double duree = std::chrono::duration<double, std::milli>(fin - debut).count();
        sommeTemps += duree;
    }

    double moyenne = sommeTemps / nbImages;

    std::cout << "Iterations par image : " << nbIterations << std::endl;
    std::cout << "Nombre d'images      : " << nbImages << std::endl;
    std::cout << "Temps moyen par image : " << moyenne << " ms" << std::endl;
    std::cout << "Valeur temoin          : " << accumulateur << std::endl;

    return 0;
}
