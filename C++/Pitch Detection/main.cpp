#include "pitch_detector.hpp"


using namespace std;


int main()
{
    string path = "../../Audio/guitar_G3.wav";
    int step = 1024;
    int window_size = 2 * 1024;
    Pitch_Detector pd(path, step, window_size);
    cout << "Gotovo je obrada, procenjena note je: " << pd.note_estim() << endl;

    return 0;
}
