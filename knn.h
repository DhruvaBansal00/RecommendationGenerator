#include <queue>
#include "readDataset.h"

using namespace std;

class ContentKNN {
    public:
        unordered_map<string, unordered_map<string, double>*> *similarity_scores;

        ContentKNN(ReadData* dataset);
        ~ContentKNN();
        void compute_similarity(ReadData *dataset);
        double estimate_rating(string user, string item);
};