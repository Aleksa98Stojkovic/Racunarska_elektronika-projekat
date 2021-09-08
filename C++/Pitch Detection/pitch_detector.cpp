#include "pitch_detector.hpp"

using namespace std;

Pitch_Detector::Pitch_Detector(const string &filename, const int &step, const int &window_size)
{

    AudioFile<double> audioFile;
    audioFile.load(filename);
    this->sampling_rate = (real)audioFile.getSampleRate();
    this->num_of_samples = (int)audioFile.getNumSamplesPerChannel();

    for (int i = 0; i < this->num_of_samples; i++)
    {
        this->wave.push_back((real)audioFile.samples[0][i]);
    }

    // Popunjavanje mape
    this->pitch_pairs.insert(make_pair(65.41, "C2"));
    this->pitch_pairs.insert(make_pair(69.3, "C2#"));
    this->pitch_pairs.insert(make_pair(73.42, "D2"));
    this->pitch_pairs.insert(make_pair(77.78, "E2b"));
    this->pitch_pairs.insert(make_pair(82.41, "E2"));
    this->pitch_pairs.insert(make_pair(87.31, "F2"));
    this->pitch_pairs.insert(make_pair(92.5, "F2#"));
    this->pitch_pairs.insert(make_pair(98.0, "G2"));
    this->pitch_pairs.insert(make_pair(103.8, "G2#"));
    this->pitch_pairs.insert(make_pair(110.0, "A2"));
    this->pitch_pairs.insert(make_pair(116.5, "B2b"));
    this->pitch_pairs.insert(make_pair(123.5, "B2"));
    this->pitch_pairs.insert(make_pair(130.8, "C3"));
    this->pitch_pairs.insert(make_pair(138.6, "C3#"));
    this->pitch_pairs.insert(make_pair(146.8, "D3"));
    this->pitch_pairs.insert(make_pair(155.6, "E3b"));
    this->pitch_pairs.insert(make_pair(164.8, "E3"));
    this->pitch_pairs.insert(make_pair(174.6, "F3"));
    this->pitch_pairs.insert(make_pair(185.0, "F3#"));
    this->pitch_pairs.insert(make_pair(196.0, "G3"));
    this->pitch_pairs.insert(make_pair(207.7, "G3#"));
    this->pitch_pairs.insert(make_pair(220.0, "A3"));
    this->pitch_pairs.insert(make_pair(233.1, "B3b"));
    this->pitch_pairs.insert(make_pair(246.9, "B3"));
    this->pitch_pairs.insert(make_pair(261.6, "C4"));
    this->pitch_pairs.insert(make_pair(277.2, "C4#"));
    this->pitch_pairs.insert(make_pair(293.7, "D4"));
    this->pitch_pairs.insert(make_pair(311.1, "E4b"));
    this->pitch_pairs.insert(make_pair(329.6, "E4"));
    this->pitch_pairs.insert(make_pair(349.2, "F4"));
    this->pitch_pairs.insert(make_pair(370.0, "F4#"));
    this->pitch_pairs.insert(make_pair(392.0, "G4"));
    this->pitch_pairs.insert(make_pair(415.3, "G4#"));
    this->pitch_pairs.insert(make_pair(440.0, "A4"));
    this->pitch_pairs.insert(make_pair(466.2, "B4b"));
    this->pitch_pairs.insert(make_pair(493.9, "B4"));
    this->pitch_pairs.insert(make_pair(523.3, "C5"));
    this->pitch_pairs.insert(make_pair(554.4, "C5#"));
    this->pitch_pairs.insert(make_pair(587.3, "D5"));
    this->pitch_pairs.insert(make_pair(622.3, "E5b"));
    this->pitch_pairs.insert(make_pair(659.3, "E5"));
    this->pitch_pairs.insert(make_pair(698.5, "F5"));
    this->pitch_pairs.insert(make_pair(740.0, "F5#"));
    this->pitch_pairs.insert(make_pair(784.0, "G5"));
    this->pitch_pairs.insert(make_pair(830.6, "G5#"));
    this->pitch_pairs.insert(make_pair(880.0, "A5"));
    this->pitch_pairs.insert(make_pair(932.3, "B5b"));
    this->pitch_pairs.insert(make_pair(987.8, "B5"));
    this->pitch_pairs.insert(make_pair(1047.0, "C6"));
    this->pitch_pairs.insert(make_pair(1109.0, "C6#"));
    this->pitch_pairs.insert(make_pair(1175.0, "D6"));
    this->pitch_pairs.insert(make_pair(1245.0, "E6b"));
    this->pitch_pairs.insert(make_pair(1319.0, "E6"));
    this->pitch_pairs.insert(make_pair(1397.0, "F6"));
    this->pitch_pairs.insert(make_pair(1480.0, "F6#"));
    this->pitch_pairs.insert(make_pair(1568.0, "G6"));
    this->pitch_pairs.insert(make_pair(1661.0, "G6#"));
    this->pitch_pairs.insert(make_pair(1760.0, "A6"));
    this->pitch_pairs.insert(make_pair(1865.0, "B6b"));
    this->pitch_pairs.insert(make_pair(1976.0, "B6"));
    this->pitch_pairs.insert(make_pair(2093.0, "C7"));

    // Upisujem pojedinacne frekvencije
    this->freq.push_back(65.41);
    this->freq.push_back(69.3);
    this->freq.push_back(73.42);
    this->freq.push_back(77.78);
    this->freq.push_back(82.41);
    this->freq.push_back(87.31);
    this->freq.push_back(92.5);
    this->freq.push_back(98.0);
    this->freq.push_back(103.8);
    this->freq.push_back(110.0);
    this->freq.push_back(116.5);
    this->freq.push_back(123.5);
    this->freq.push_back(130.8);
    this->freq.push_back(138.6);
    this->freq.push_back(146.8);
    this->freq.push_back(155.6);
    this->freq.push_back(164.8);
    this->freq.push_back(174.6);
    this->freq.push_back(185.0);
    this->freq.push_back(196.0);
    this->freq.push_back(207.7);
    this->freq.push_back(220.0);
    this->freq.push_back(233.1);
    this->freq.push_back(246.9);
    this->freq.push_back(261.6);
    this->freq.push_back(277.2);
    this->freq.push_back(293.7);
    this->freq.push_back(311.1);
    this->freq.push_back(329.6);
    this->freq.push_back(349.2);
    this->freq.push_back(370.0);
    this->freq.push_back(392.0);
    this->freq.push_back(415.3);
    this->freq.push_back(440.0);
    this->freq.push_back(466.2);
    this->freq.push_back(493.9);
    this->freq.push_back(523.3);
    this->freq.push_back(554.4);
    this->freq.push_back(587.3);
    this->freq.push_back(622.3);
    this->freq.push_back(659.3);
    this->freq.push_back(698.5);
    this->freq.push_back(740.0);
    this->freq.push_back(784.0);
    this->freq.push_back(830.6);
    this->freq.push_back(880.0);
    this->freq.push_back(932.3);
    this->freq.push_back(987.8);
    this->freq.push_back(1047.0);
    this->freq.push_back(1109.0);
    this->freq.push_back(1175.0);
    this->freq.push_back(1245.0);
    this->freq.push_back(1319.0);
    this->freq.push_back(1397.0);
    this->freq.push_back(1480.0);
    this->freq.push_back(1568.0);
    this->freq.push_back(1661.0);
    this->freq.push_back(1760.0);
    this->freq.push_back(1865.0);
    this->freq.push_back(1976.0);
    this->freq.push_back(2093.0);


    this->step = step;
    this->window_size = window_size;
}

int Pitch_Detector::my_find(const vector<real> &arr)
{

    int index = 0;
    for(int i = 0; i < (int)arr.size(); i++)
    {
        if(arr[i] > 0)
        {
            index = i;
            break;
        }
    }

    return index;
}

void Pitch_Detector::parabolic(const real &f_left, const real &f_max, const real &f_right, more_real &x, const int &max_index)
{
    more_real n = 0.5 * ((more_real)f_left - (more_real)f_right);
    more_real d = ((more_real)f_left - 2 * (more_real)f_max + (more_real)f_right);

    if(d != 0)
        x = n / d + (more_real)max_index;
    else
        x = pow(10.0, 6);

}

real Pitch_Detector::find_nearest(const vector<real> &arr, const real &value)
{

    int index = 0;
    real min_val = abs(arr[0] - value);

    for(int i = 1; i < (int)arr.size(); i++)
    {
        if(min_val > abs(arr[i] - value))
        {
            index = i;
            min_val = abs(arr[i] - value);
        }
    }

    return arr[index];
}

void Pitch_Detector::autocorrelation(vector<real> &arr)
{
    int len = arr.size();
    vector<real> result;

    for(int i = 0; i < len; i++)
    {
        int offset = len - i - 1;
        int length = i + 1;
        real acc = 0;

        for(int j = 0; j < length; j++)
        {
            acc += arr[j] * arr[j + offset];
        }

        result.push_back(acc);
    }

    arr.clear();
    for(int i = len - 1; i >= 0; i--)
    {
        arr.push_back(result[i]);
    }

    result.clear();
}

void Pitch_Detector::freq_from_autocorr(vector<real> &arr)
{
    autocorrelation(arr);
    vector <real> diff;

    // Trazimo najveci skok
    for(int i = 1; i < (int)arr.size(); i++)
        diff.push_back(arr[i] - arr[i - 1]);

    int start = my_find(diff);

    // Trazimo indeks najveceg elementa od kada se desio najveci skok
    int peak = start;
    real max_val = arr[start];
    for(int i = start + 1; i < (int)arr.size(); i++)
    {
        if(max_val < arr[i])
        {
            max_val = arr[i];
            peak = i;
        }
    }

    real x;
    parabolic(arr[peak - 1], arr[peak], arr[peak + 1], x, peak);

    // cout << "C++ vrednost peak-a je: " << peak << endl;

    arr.clear();
    arr.push_back(this->sampling_rate / (real)x);

}

string Pitch_Detector::note_estim()
{

    std::tr1::unordered_map<string, int> dict;

    int iter_num = this->num_of_samples / this->step;
    iter_num -= iter_num % 8; // imacu 4 niti za sada


    for(int i = 0; i < iter_num; i += 8)
    {
        // cout << "Iteracija: " << i << endl;

        vector <real> subset1;
        vector <real> subset2;
        vector <real> subset3;
        vector <real> subset4;
        vector <real> subset5;
        vector <real> subset6;
        vector <real> subset7;
        vector <real> subset8;

        subset1.reserve(this->window_size);
        subset2.reserve(this->window_size);
        subset3.reserve(this->window_size);
        subset4.reserve(this->window_size);
        subset5.reserve(this->window_size);
        subset6.reserve(this->window_size);
        subset7.reserve(this->window_size);
        subset8.reserve(this->window_size);

        int i_t = i;
        // --------------- Priprema za nit1 --------------- //

        if((int)(this->wave).size() - i_t * this->step >= this->window_size)
        {
            for(int j = 0; j < this->window_size; j++)
            {
                subset1.push_back(this->wave[j + i_t * this->step]);
            }
        }
        else
        {
            for(int j = 0; j < this->window_size; j++)
            {
                if(j < (int)(this->wave).size() - i_t * this->step)
                    subset1.push_back(this->wave[j + i_t * this->step]);
                else
                    subset1.push_back(0);
            }
        }

        // --------------- Priprema za nit2 --------------- //

        i_t = i + 1;

        if((int)(this->wave).size() - i_t * this->step >= this->window_size)
        {
            for(int j = 0; j < this->window_size; j++)
            {
                subset2.push_back(this->wave[j + i_t * this->step]);
            }
        }
        else
        {
            for(int j = 0; j < this->window_size; j++)
            {
                if(j < (int)(this->wave).size() - i_t * this->step)
                    subset2.push_back(this->wave[j + i_t * this->step]);
                else
                    subset2.push_back(0);
            }
        }

        // --------------- Priprema za nit3 --------------- //

        i_t = i + 2;

        if((int)(this->wave).size() - i_t * this->step >= this->window_size)
        {
            for(int j = 0; j < this->window_size; j++)
            {
                subset3.push_back(this->wave[j + i_t * this->step]);
            }
        }
        else
        {
            for(int j = 0; j < this->window_size; j++)
            {
                if(j < (int)(this->wave).size() - i_t * this->step)
                    subset3.push_back(this->wave[j + i_t * this->step]);
                else
                    subset3.push_back(0);
            }
        }

        // --------------- Priprema za nit4 --------------- //


        i_t = i + 3;

        if((int)(this->wave).size() - i_t * this->step >= this->window_size)
        {
            for(int j = 0; j < this->window_size; j++)
            {
                subset4.push_back(this->wave[j + i_t * this->step]);
            }
        }
        else
        {
            for(int j = 0; j < this->window_size; j++)
            {
                if(j < (int)(this->wave).size() - i_t * this->step)
                    subset4.push_back(this->wave[j + i_t * this->step]);
                else
                    subset4.push_back(0);
            }
        }


        // --------------------------------------------- //

        // --------------- Priprema za nit5 --------------- //

        i_t = i + 4;
        if((int)(this->wave).size() - i_t * this->step >= this->window_size)
        {
            for(int j = 0; j < this->window_size; j++)
            {
                subset5.push_back(this->wave[j + i_t * this->step]);
            }
        }
        else
        {
            for(int j = 0; j < this->window_size; j++)
            {
                if(j < (int)(this->wave).size() - i_t * this->step)
                    subset5.push_back(this->wave[j + i_t * this->step]);
                else
                    subset5.push_back(0);
            }
        }

        // --------------- Priprema za nit2 --------------- //

        i_t = i + 5;

        if((int)(this->wave).size() - i_t * this->step >= this->window_size)
        {
            for(int j = 0; j < this->window_size; j++)
            {
                subset6.push_back(this->wave[j + i_t * this->step]);
            }
        }
        else
        {
            for(int j = 0; j < this->window_size; j++)
            {
                if(j < (int)(this->wave).size() - i_t * this->step)
                    subset6.push_back(this->wave[j + i_t * this->step]);
                else
                    subset6.push_back(0);
            }
        }

        // --------------- Priprema za nit3 --------------- //

        i_t = i + 6;

        if((int)(this->wave).size() - i_t * this->step >= this->window_size)
        {
            for(int j = 0; j < this->window_size; j++)
            {
                subset7.push_back(this->wave[j + i_t * this->step]);
            }
        }
        else
        {
            for(int j = 0; j < this->window_size; j++)
            {
                if(j < (int)(this->wave).size() - i_t * this->step)
                    subset7.push_back(this->wave[j + i_t * this->step]);
                else
                    subset7.push_back(0);
            }
        }

        // --------------- Priprema za nit4 --------------- //


        i_t = i + 7;

        if((int)(this->wave).size() - i_t * this->step >= this->window_size)
        {
            for(int j = 0; j < this->window_size; j++)
            {
                subset8.push_back(this->wave[j + i_t * this->step]);
            }
        }
        else
        {
            for(int j = 0; j < this->window_size; j++)
            {
                if(j < (int)(this->wave).size() - i_t * this->step)
                    subset8.push_back(this->wave[j + i_t * this->step]);
                else
                    subset8.push_back(0);
            }
        }


        // --------------------------------------------- //

        thread t1(&Pitch_Detector::freq_from_autocorr, *this, std::ref(subset1));
        thread t2(&Pitch_Detector::freq_from_autocorr, *this, std::ref(subset2));
        thread t3(&Pitch_Detector::freq_from_autocorr, *this, std::ref(subset3));
        thread t4(&Pitch_Detector::freq_from_autocorr, *this, std::ref(subset4));
        thread t5(&Pitch_Detector::freq_from_autocorr, *this, std::ref(subset5));
        thread t6(&Pitch_Detector::freq_from_autocorr, *this, std::ref(subset6));
        thread t7(&Pitch_Detector::freq_from_autocorr, *this, std::ref(subset7));
        thread t8(&Pitch_Detector::freq_from_autocorr, *this, std::ref(subset8));

        t1.join();
        t2.join();
        subset1.push_back(subset2[0]);
        subset2.clear();
        t3.join();
        subset1.push_back(subset3[0]);
        subset3.clear();
        t4.join();
        subset1.push_back(subset4[0]);
        subset4.clear();
        t5.join();
        subset1.push_back(subset5[0]);
        subset5.clear();
        t6.join();
        subset1.push_back(subset6[0]);
        subset6.clear();
        t7.join();
        subset1.push_back(subset7[0]);
        subset7.clear();
        t8.join();
        subset1.push_back(subset8[0]);
        subset8.clear();

        // cout << "Procenjena frekvencija je: " << f_estim << endl;

        for(auto f_estim : subset1)
        {
             // cout << "Procenjena frekvencija je: " << f_estim << endl;

            if(f_estim <= 2100.0 && f_estim >= 50.0)
            {
                string note = this->pitch_pairs[find_nearest(this->freq, f_estim)];
                // cout << "Procenjena nota je: " << note << endl;
                // Ovo ispituje da li se nota ne nalazi u mapi
                if(dict.find(note) == dict.end())
                    dict.insert(make_pair(note, 0));
                else
                    dict[note] = dict[note] + 1;
            }
        }

        subset1.clear();

    }

    // Treba da prodjem kroz sve parove i nadjem onaj sa navecom vrednoscu
    int max_val = -1;
    string estim_note;

    for (const auto & [key, value] : dict)
    {
        if(value > max_val)
        {
            estim_note = key;
            max_val = value;
        }
    }

    // cout << "String je: " << estim_note << endl;

    return estim_note;
}
