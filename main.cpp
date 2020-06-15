 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */
 /*
*/
#include <iostream>
#include <string>
#include <vector>
//namespace Part2Version 
/*
{
struct CarWash
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
*/
//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    struct Foot
    {
        int stepSize(int length);
        void stepForward();
    };

    Foot leftFoot;
    Foot rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

int Person::Foot::stepSize(int length)
{
    return length;
}

void Person::Foot::stepForward() {}

void Person::run(int howFast, bool startWithLeftFoot)
{
    if(startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += leftFoot.stepSize(howFast) + rightFoot.stepSize(howFast);
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you decide to write empty functions, you will need to fill them in with code in part 3.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 */

struct Prophet6
{
    int numOscillators = 12;
    bool fxOn = true;
    float filterCutoff = 0.5f;
    float distortion = 0.01f;
    int note = 32;
    int currentNote;

    struct Globals
    {
        int transposeSemiTone = 0;
        int masterTuneCents = 0; 
        int midiChannel = 1;
        int transmitMidiClock = false; 
        bool usingUSBForMidiClock = false; 

        void setTransposition(int semitones); 
        void setMasterTune(int cents);
        void setMidiChannel(int channel);
    };

    void modCutoff(float filterCutoff);
    void playSequence();
    bool engageFX(bool fxOn);
};

void Prophet6::Globals::setTransposition(int semitones)
{
    transposeSemiTone += semitones;
}

void Prophet6::Globals::setMasterTune(int cents)
{
    masterTuneCents += cents;
}

void Prophet6::Globals::setMidiChannel(int channel)
{
    midiChannel = channel;
}

void Prophet6::modCutoff(float lfo)
{
    filterCutoff += lfo;
}
void Prophet6::playSequence()
{}

bool Prophet6::engageFX(bool fxCurrentlyOn)
{
    if(fxCurrentlyOn == true)
    {
        fxOn = false;
    }
    else
    {
        fxCurrentlyOn = true;
    }
    return fxOn;
}

struct Tr808
{
    int numVoices = 11;
    bool stepTrig = true;
    float voiceLevel = -2.3f;
    int preset = 12;
    int tempo = 135;
    bool sequence[16];
    float tone = 12.5f;

    void playSequence();
    void adjustTone(float knobTurn);
    void adjustLevel(float knobTurn);
};

void Tr808::playSequence()
{}

void Tr808::adjustTone(float knobTurn)
{
    tone += knobTurn;
}
void Tr808::adjustLevel(float knobTurn)
{
    voiceLevel += knobTurn;
}

struct ElectricGuitar
{
    float volume = 10.0f;
    float tone = 12.2f;
    int strings = 6;
    float tunePegCents = 12.0f;
    bool seymourDuncanPickups = true;

    bool shouldPlayMusic(bool isInTune, int numStrings);
    bool willFeedback(float volume, float tone, float ampGain);
    void tuneAString(int aStringHz);
};



bool ElectricGuitar::shouldPlayMusic(bool isInTune, int numStrings = 6)
{
    return (isInTune == true && numStrings == 6);
}

bool ElectricGuitar::willFeedback(float volumeKnob, float toneKnob, float ampGain)
{
    float feedbackThreshold = 50.2f;
    return ((volumeKnob + toneKnob) * ampGain > feedbackThreshold);
}
void ElectricGuitar::tuneAString(int aStringHz)
{
    if (aStringHz != 110)
    {
       int tuningDifference = 110 - aStringHz;
       tunePegCents += tuningDifference;
    }
}

struct GranularSynth
{
    float grainSize = 0.6f;
    int grainDensity = 7;
    float playbackPosition = 0.0;
    float varispeed = 1.0f;
    double random = 0.12;

    void changeVarispeed(float change);
    void slide(float modulationInput);
    void modGrainSize(float modulationInput);
};

void GranularSynth::changeVarispeed(float change)
{
    varispeed += change;
}

void GranularSynth::slide(float modulationInput)
{
    playbackPosition += modulationInput;
}

void GranularSynth::modGrainSize(float modulationInput)
{
    grainSize += modulationInput;
}

struct Oscillator
{
    int negativeTwelvePower = 40;
    int positiveTwelvePower = 30;
    float waveshape = 12.4f;
    int outputType = 2;
    float fmAttenuator = 0.46f;
    float phase = 0.0f;

    bool outputWave(int negativePower, int positivePower);
    void hardSync(std::vector<double> inputSignal);
    void receivePitchCV(float inputVoltage, float fmAttenuator);
    void resetPhase();
};

bool Oscillator::outputWave(int negativePower, int positivePower)
{
    return (negativePower >= negativeTwelvePower && positivePower >= positiveTwelvePower);
} 

void Oscillator::resetPhase()
{
    phase = 0.0f;
}

void Oscillator::hardSync(std::vector<double> inputSignal)
{
    //Don't know enough about DFT and how to apply it to coding yet. I apologize for getting a bit overambitious with the methods. resetPhase() function is there so that it can be used but I don't know what its definition should be yet
    for (unsigned long i = 0; i < inputSignal.size(); ++i)
    {
        //when a value in the array/signal is zero, the signal's cycle is at the beginning of its phase
        if (inputSignal[i] == 0.0)
        {
            resetPhase();
        }
    }
}


struct Filter
{
    int filterType = 1;
    float fmAttenuator = 0.56f;
    float cutoff = 56.23f;
    float resonance = 15.54f;
    float gain = 12.3f;

    void changeResonance(float change);
    void trackPitch(float cv);
    void modFilter(float cv);
};

void Filter::changeResonance(float change)
{
    resonance += change;
}

void Filter::trackPitch(float cv)
{
    cutoff += cv;
}

void Filter::modFilter(float cv)
{
    //fmAttenuator works between values of 0.0f and 1.0f
    cutoff += cv * fmAttenuator;
    
}

struct Envelope
{
    int attack = 243;
    int decay = 501;
    float sustain = 0.67f;
    int release = 684;
    int hold = 43;
    bool cycleSwitchOn = true;

    bool willOutputCV(bool powerOn, bool gateHigh);
    bool receiveGate(bool cycleModeOn = false);
    void cycleMode();
};

bool Envelope::willOutputCV(bool powerOn, bool gateHigh)
{
    return powerOn && gateHigh;
}

bool Envelope::receiveGate(bool cycleModeOn)
{
    return (cycleModeOn == false);
}

void Envelope::cycleMode()
{
    cycleSwitchOn = !cycleSwitchOn;
}

struct DualVCA
{
    int audioInputs = 2;
    int cvInputs = 2;
    bool cvInputUsed = false;
    bool boostSwitch = true;
    int audioOutputs = 2;
    float cvInputOne = 12.02f;
    float cvInputTwo = 0.0f;
    bool muteOn = false;

    void cascadeCV();
    void boost();
    void mute();
};
void DualVCA::cascadeCV()
{
    for (int i = 0; i <= cvInputs; ++i)
    {
        if (cvInputUsed == false)
        {
            cvInputTwo = cvInputOne;
        }
    }
}


void DualVCA::boost()
{
    boostSwitch = !boostSwitch;
}

void DualVCA::mute()
{
    muteOn = !muteOn;
}


struct CVSequencer
{
    int cvChannels = 8;
    float outputLevel = 2.3f;
    int steps = 16;
    int trigPerStep = 1;
    int scale = 2;

    void changeNumSteps(int newNumSteps);
    void divideClock(int division);
    std::vector<int> arp(int numStepsPressed);
};

void CVSequencer::changeNumSteps(int newNumSteps)
{
    steps = newNumSteps;
}

void CVSequencer::divideClock(int division)
{
    trigPerStep *= division;
}

std::vector<int> CVSequencer::arp(int numStepsPressed)
{
    std::vector<int> arp; 
    for (int i = 0; i <= numStepsPressed; ++i)
    {
        int stepNum;
        std::cin >> stepNum;
        arp.push_back(stepNum);
    }
    return arp;
}

struct ModularSynth
{
    Oscillator oscillator;
    Filter flter;
    Envelope envelope;  
    DualVCA vca;
    CVSequencer cvsequencer;
    int emptyHP = 12;

    struct Module
    {
        int negativeTwelvePower;
        int positiveTwelvePower;
        int hp;
        bool threeU = true;
        int numberOfInputs;

        bool outputVoltage(int negativePower, int positivePower);
        int getHP();
        bool isEurorack(int u);
    };

    void patch(std::string output, std::string input);
    void unpatch(std::string output, std::string input);
    void modDecayEnv(std::string cvSource);
};

bool ModularSynth::Module::outputVoltage(int negativePower, int positivePower)
{
    return (negativePower >= negativeTwelvePower && positivePower >= negativeTwelvePower);
}

int ModularSynth::Module::getHP()
{
    return hp;
}

bool ModularSynth::Module::isEurorack(int u)
{
    return (u == 3);
}

void ModularSynth::patch(std::string output, std::string input)
{
    std::cout << output << " has been patched into " << input << "!\n";
}

void ModularSynth::unpatch(std::string output, std::string input)
{
    std::cout << output << " has been unpatched from " << input << "!\n";
}

void ModularSynth::modDecayEnv(std::string cvSource)
{
    patch(cvSource, "Decay");
}






/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
