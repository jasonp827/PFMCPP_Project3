/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to your types. 
 
 2) use while() or for() loops to do something interesting inside these new member functions.
         a) for example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //3), 4c) 
    {
        Bar bar(startingVal);                //4a)
        while( bar.num < threshold )         //4a) 
        { 
            bar.num += 1;                    //4a)
            
            if( bar.num >= threshold )       //4b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //5) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //6) 
    return 0;
}
}

//call Example::main() in main()





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

Prophet6::Prophet6() :
fxOn(true),
filterCutoff(0.5f)
{}

Prophet6::Globals::Globals() :
transposeSemiTone(0),
masterTuneCents(0),
midiChannel(1),     
transmitMidiClock(false),
usingUSBForMidiClock(false)
{}

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
    bool stepTrig{true};
    float voiceLevel{0.0f};
    int preset{0};
    int tempo = 135;
    bool sequence[16];
    float tone{12.5};

    void playSequence();
    void adjustTone(float knobTurn);
    void adjustLevel(float knobTurn);
};

Tr808::Tr808()
{}

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
    float volume{10.0f};
    float tone{10.0f};
    int strings = 6;
    float tunePegCents = 12.0f;
    bool seymourDuncanPickups{true};

    bool shouldPlayMusic(bool isInTune, int numStrings);
    bool willFeedback(float volume, float tone, float ampGain);
    void tuneAString(int aStringHz);
};

ElectricGuitar::ElectricGuitar()
{}

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

GranularSynth::GranularSynth() :
grainSize(1.0f),
grainDensity(7),
playbackPosition(0.0f),
varispeed(1.0f),
random(0.0)
{}

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

Oscillator::Oscillator() :
negativeTwelvePower(40),
positiveTwelvePower(30),
waveshape(12.4f),
outputType(2)
{}

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
    int filterType{1};
    float fmAttenuator{0.0f};
    float cutoff{1.0f};
    float resonance{0.0f};
    float gain{10.0f};

    void changeResonance(float change);
    void trackPitch(float cv);
    void modFilter(float cv);
};

Filter::Filter()
{}

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
    int attack{0};
    int decay{500};
    float sustain{0.5f};
    int release{200};
    int hold{0};
    bool cycleSwitchOn{false};

    bool willOutputCV(bool powerOn, bool gateHigh);
    bool receiveGate(bool cycleModeOn = false);
    void cycleMode();
};

Envelope::Envelope()
{}

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

VCA::VCA() : 
audioInputs(2),
cvInputs(2),
audioOutputs(2),
muteOn(false)
{}

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
    std::cout << "Mute: " << (muteOn == true ? "On" : "Off") << "\n";
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

CVSequencer::CVSequencer() :
cvChannels(8),
outputLevel(0),
scale(2)
{}

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
        int negativeTwelvePower{0};
        int positiveTwelvePower{0};
        int hp{0};
        int u{0};
        int numberOfInputs{0};

        bool outputVoltage(int negativePower, int positivePower);
        int getHP();
        bool isEurorack();
    };

    void patch(std::string output, std::string input);
    void unpatch(std::string output, std::string input);
    void modDecayEnv(std::string cvSource);
};

ModularSynth::ModularSynth() :
emptyHP(12)
{}

ModularSynth::Module::Module()
{}

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
