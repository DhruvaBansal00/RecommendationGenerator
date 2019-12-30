#include "splitData.h"

void SplitDataset::add(string user, string item, string rating, unordered_map<string, unordered_map<string, string>*>* set) {
    if ((*set).count(user) == 0) {
        (*set)[user] = new unordered_map<string, string>;
    }
    (*(*set)[user])[item] = rating;
}

SplitDataset::SplitDataset(ReadData* data, double testProp) {
    testset = new unordered_map<string, unordered_map<string, string>*>;
    trainset = new unordered_map<string, unordered_map<string, string>*>;
    srand(time(0));
    for (auto const & pair1 : *(*data).user_to_item_rating) {
        for (auto const & pair2 : *pair1.second) {
            if (random()/(double(RAND_MAX) <= testProp)) {
                add(pair1.first, pair2.first, pair2.second, testset);
            } else {
                add(pair1.first, pair2.first, pair2.second, trainset);
            }
        }
    }
}

SplitDataset::~SplitDataset() {
    for (auto const & pair : *testset) {
        delete pair.second;
    }
    delete testset;

    for (auto const & pair : *trainset) {
        delete pair.second;
    }
    delete trainset;
}
