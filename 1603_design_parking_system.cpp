class ParkingSystem {
  public:
    ParkingSystem(int big, int medium, int small) {
        this->places[0] = big;
        this->places[1] = medium;
        this->places[2] = small;
    }

    bool addCar(int carType) {
        // nothing to comment, think its pretty obvious problem
        if (this->places[carType - 1] > 0) {
            this->places[carType - 1]--;
            return true;
        }

        return false;
    }

  private:
    int places[3];
};
