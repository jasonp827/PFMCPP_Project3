/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 1) Add a constructor for each User-Defined-Type. done
 
 2) amend some of your UDT's member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of each of your user-defined types in the main() function

 4) call some of your UDT's amended member functions in main().
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 
 example:
 */

#include <iostream>
#include <vector>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int a; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    a = 0;
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'a' equal to 0? " << (foo.a == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.

struct Prophet6
{
    Prophet6();
    int numOscillators = 12;
    bool fxOn;
    float filterCutoff;
    float distortion = 0.01f;
    int note = 32;
    int currentNote;

    struct Globals
    {
        Globals();
        int transposeSemiTone;
        int masterTuneCents; 
        int midiChannel;
        int transmitMidiClock; 
        bool usingUSBForMidiClock; 

        void setTransposition(int semitones); 
        void setMasterTune(int cents);
        void setMidiChannel(int channel);
    };

    void modCutoff(float filterCutoff);
    void playSequence();
    void engageFX();
};

Prophet6::Prophet6()
{
    fxOn = true;
    filterCutoff = 0.5f;
}

Prophet6::Globals::Globals()
{
    transposeSemiTone = 0;
    masterTuneCents = 0; 
    midiChannel = 1;        
    transmitMidiClock = false; 
    usingUSBForMidiClock = false; 
}

void Prophet6::Globals::setTransposition(int semitones)
{
    transposeSemiTone += semitones;
    std::cout << "Semi: " << semitones << "\n";
}

void Prophet6::Globals::setMasterTune(int cents)
{
    masterTuneCents += cents;
    std::cout << "Cent: " << cents << "\n";
}

void Prophet6::Globals::setMidiChannel(int channel)
{
    midiChannel = channel;
    std::cout << "MiCh: " << midiChannel << "\n";
}

void Prophet6::modCutoff(float lfo)
{
    filterCutoff += lfo;
}
void Prophet6::playSequence()
{}

void Prophet6::engageFX()
{
    fxOn = !fxOn;
    std::cout << "FX: "<< (fxOn == true ? "On" : "Off") << "\n";
}

struct Tr808
{
    Tr808();
    int numVoices = 11;
    bool stepTrig;
    float voiceLevel;
    int preset;
    int tempo = 135;
    bool sequence[16];
    float tone;

    void playSequence();
    void adjustTone(float knobTurn);
    void adjustLevel(float knobTurn);
};

Tr808::Tr808()
{
    stepTrig = true;
    voiceLevel = 0.0f;
    preset = 0;
    tone = 12.5f;
}
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
    ElectricGuitar();
    float volume;
    float tone;
    int strings = 6;
    float tunePegCents = 12.0f;
    bool seymourDuncanPickups;

    bool shouldPlayMusic(bool isInTune, int numStrings);
    bool willFeedback(float volume, float tone, float ampGain);
    void tuneAString(int aStringHz);
};

ElectricGuitar::ElectricGuitar()
{
    volume = 10.0f;
    tone = 10.0f;
    seymourDuncanPickups = true;
}

bool ElectricGuitar::shouldPlayMusic(bool isInTune, int numStrings = 6)
{
    if(isInTune == true && numStrings == 6)
    {
        std::cout << "Shred it!\n";
        return true;
    }
    else
    {
        std::cout <<  "String up and tune first!\n";
        return false;
    }
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
    GranularSynth();
    float grainSize;
    int grainDensity;
    float playbackPosition;
    float varispeed;
    double random;

    void changeVarispeed(float change);
    void slide(float modulationInput);
    void modGrainSize(float modulationInput);
};

GranularSynth::GranularSynth()
{
    grainSize = 1.0f;
    grainDensity = 7;
    playbackPosition = 0.0f;
    varispeed = 1.0f;
    random = 0.0;
}

void GranularSynth::changeVarispeed(float change)
{
    varispeed += change;
    std::cout << "varispeed: " << varispeed << "\n";
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
    Oscillator();
    int negativeTwelvePower;
    int positiveTwelvePower;
    float waveshape;
    int outputType;
    float fmAttenuator = 0.0f;
    float phase = 0.0f;

    bool outputWave(int negativePower, int positivePower);
    void hardSync(std::vector<double> inputSignal);
    void receivePitchCV(float inputVoltage, float fmAttenuator);
    void resetPhase();
};

Oscillator::Oscillator()
{
    negativeTwelvePower = 40;
    positiveTwelvePower = 30;
    waveshape = 12.4f;
    outputType = 2;
}

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
    Filter();
    int filterType;
    float fmAttenuator;
    float cutoff;
    float resonance;
    float gain;

    void changeResonance(float change);
    void trackPitch(float cv);
    void modFilter(float cv);
};

Filter::Filter()
{
    filterType = 1;
    fmAttenuator = 0.0f;
    cutoff = 1.0f;
    resonance = 0.0f;
    gain = 10.0f;
}

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
    Envelope();
    int attack;
    int decay;
    float sustain;
    int release;
    int hold;
    bool cycleSwitchOn;

    bool willOutputCV(bool powerOn, bool gateHigh);
    bool receiveGate(bool cycleModeOn = false);
    void cycleMode();
};

Envelope::Envelope()
{
    attack = 0;
    decay = 500;
    sustain = 0.5f;
    release = 200;
    hold = 0;
    cycleSwitchOn = false;
}

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

struct VCA
{
    VCA();
    int audioInputs;
    int cvInputs;
    bool cvInputUsed = false;
    bool boostSwitch = true;
    int audioOutputs;
    float cvInputOne = 12.02f;
    float cvInputTwo = 0.0f;
    bool muteOn;

    void cascadeCV();
    void boost();
    void mute();
};

VCA::VCA()
{
    audioInputs = 2;
    cvInputs = 2;
    audioOutputs = 2;
    muteOn = false;
}

void VCA::cascadeCV()
{
    for (int i = 0; i <= cvInputs; ++i)
    {
        if (cvInputUsed == false)
        {
            cvInputTwo = cvInputOne;
        }
    }
}


void VCA::boost()
{
    boostSwitch = !boostSwitch;
}

void VCA::mute()
{
    muteOn = !muteOn;
}


struct CVSequencer
{
    CVSequencer();
    int cvChannels;
    float outputLevel;
    int steps = 16;
    int trigPerStep = 1;
    int scale;

    void changeNumSteps(int newNumSteps);
    void divideClock(int division);
    std::vector<int> arp(int numStepsPressed);
};

CVSequencer::CVSequencer()
{
    cvChannels = 8;
    outputLevel = 0;
    scale = 2;
}

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
        int stepNum = 1;
        std::cout << stepNum;
        arp.push_back(stepNum);
    }
    return arp;
}

struct ModularSynth
{
    ModularSynth();
    Oscillator oscillator;
    Filter flter;
    Envelope envelope;  
    VCA vca;
    CVSequencer cvsequencer;
    int emptyHP;

    struct Module
    {
        Module();
        int negativeTwelvePower;
        int positiveTwelvePower;
        int hp;
        int u;
        int numberOfInputs;

        bool outputVoltage(int negativePower, int positivePower);
        int getHP();
        bool isEurorack();
    };

    void patch(std::string output, std::string input);
    void unpatch(std::string output, std::string input);
    void modDecayEnv(std::string cvSource);
};

ModularSynth::ModularSynth()
{
    emptyHP = 12;
}
ModularSynth::Module::Module()
{
    negativeTwelvePower = 0;
    positiveTwelvePower = 0;
    hp = 0;
    u = 0;
    numberOfInputs = 0;
}

bool ModularSynth::Module::outputVoltage(int negativePower, int positivePower)
{
    return (negativePower >= negativeTwelvePower && positivePower >= negativeTwelvePower);
}

int ModularSynth::Module::getHP()
{
    return hp;
}

bool ModularSynth::Module::isEurorack()
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
    Example::main();

    Prophet6 myProphet6, yourProphet6;
    Prophet6::Globals myGlobals;

    Tr808 aTr808;
    ElectricGuitar myElectricGuitar;
    GranularSynth morphagene;
    Oscillator sto, csL;
    Filter sem20, ladderFilter;
    Envelope mnFunction, quadra;
    VCA dualVCA;
    CVSequencer voltageBlock;
    ModularSynth myEurorack;

    ModularSynth::Module echophon, mixUp;

    myEurorack.patch("STO sine output", "Echophon audio in");

    myGlobals.setMidiChannel(1);

    myElectricGuitar.shouldPlayMusic(true, 6);

    std::cout << "Is guitar tone too bright? " << (myElectricGuitar.tone > 9.0f ? "Yes" : "No") << "\n";

    std::cout << "Why isn't the MIDI clock not syncing on the Prophet? \n MIDIsync: " << myGlobals.transmitMidiClock << "\nOh, MIDI sync is disabled.""\n";

    std::cout << "good to go!" << std::endl;
}
