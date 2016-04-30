class IWeightable {
public:
    IWeightable();
    IWeightable(int amnt, int side);

    void setLoadAmount(int amnt);
    int getLoadAmount();

    void setLoadedSide(int side);
    int getLoadedSide();

private:
    int loadAmount;
    int loadedSide;
};
