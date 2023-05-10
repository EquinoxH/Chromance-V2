namespace Random{
    void initialise();

    int getRandomInt(int max);
    int getRandomInt(int min, int max);

    int getRandomIntExcept(int max, int exclusion);
    int getRandomIntExcept(int min, int max, int exclusion);

    double getRandomDouble(double max);
    double getRandomDouble(double min, double max);

    double getRandomDoubleExcept(double max, double exclusion);
    double getRandomDoubleExcept(double min, double max, double exclusion);
}