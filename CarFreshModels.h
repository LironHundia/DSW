//
// Created by liron on 14/05/2021.
//

#ifndef DSW_CARFRESHMODELS_H
#define DSW_CARFRESHMODELS_H

class CarFreshModels {
private:
    int typeID;
    int num_of_models;
    int lowest_unsold_model;
    int *left_array;
    int *right_array;
public:
    CarFreshModels * top;
    CarFreshModels * right;
    CarFreshModels *left;
    int height;
    CarFreshModels(int typeID, int num_of_models);
    ~CarFreshModels();
    CarFreshModels(const CarFreshModels& car_fresh);

    CarFreshModels& operator=(const CarFreshModels& car_fresh);
    bool removeModel(int model);
    bool operator==(const CarFreshModels& car_fresh);
    bool operator<(const CarFreshModels& car_fresh);
    //void print();
};


#endif //DSW_CARFRESHMODELS_H
