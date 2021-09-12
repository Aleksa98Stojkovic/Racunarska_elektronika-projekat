#ifndef PITCHDETECTOR_HPP
#define PITCHDETECTOR_HPP


#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include "string.h"
#include <fstream>
#include <vector>
#include <cstdlib>
#include <memory>
#include<tr1/unordered_map>
#include "../../AudioFile/AudioFile.h"
#include <thread>

typedef float real;
typedef float more_real;

class Pitch_Detector
{
        public:

        Pitch_Detector(const int &step, const int &window_size);
        std::string note_estim();
        void load(const std::string &filename);
        real find_note(std::string freq);
        std::vector<std::string> get_notes();
        void setWave(const std::vector<real> &wave);
        void getWave(std::vector<real> &wave);

    private:

        // Parametri
        std::vector<real> wave;
        real sampling_rate;
        int num_of_samples;
        int step;
        int window_size;
        std::tr1::unordered_map<real, std::string> pitch_pairs;
        std::vector<real> freq;

        int my_find(const std::vector<real> &arr);
        void parabolic(const real &f_left, const real &f_max, const real &f_right, more_real &x, const int &max_index);
        void autocorrelation(std::vector<real> &arr);
        void freq_from_autocorr(std::vector<real> &arr);
        real find_nearest(const std::vector<real> &arr, const real &value);

};


#endif
