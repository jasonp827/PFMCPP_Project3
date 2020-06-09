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

#include <iostream>
#include <string>
namespace Part1eVersion 
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





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you decide to write empty functions, you will need to fill them in with code in part 3.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
Thing 1) Prophet-6
5 properties:
    1)  number of oscillators
    2)  FX on/off
    3)  filter cutoff amount
    4)  distortion amount
    5)  keyboard notes (int)
3 things it can do:
    1)  modulate cutoff
    2)  play sequence
    3)  turn on FX
*/

struct Prophet6
{
    //1) number of oscillators
    int numOscillators = 12;
    //2) FX on/off
    bool fxOnOff = true;
    //3) filter cutoff amount
    float filterCutoff = 0.5f;
    //4) distortion amount
    float distortion = 0.01f;
    //5) keyboard notes (unison)
    int note = 32;

    struct Globals
    {
        //1) transpose value
        int transposeSemiTone = 0;
        //2) master tune value in cents
        int masterTuneCents = 0; 
        //3) midi channel
        int midiChannel = 1;
        //4) midiClock
        int transmitMidiClock = false; 
        //5) clock port (MIDI or USB)
        bool usingUSBForMidiClock = false; 

        void setTransposition(int semitones); 
        void setMasterTune(int cents);
        void setMidiChannel(int channel);
    };

    //1) modulate cutoff
    void modCutoff(float filterCutoff);
    //2) play sequencer
    void playSequence(int note);
    //3) turn on FX
    bool engageFX(bool fxOnOff);
};

/*
Thing 2) Tr-808
5 properties:
    1)  number of voices
    2)  step trigger (bool)
    3)  level amount per voice
    4)  preset number
    5)  tempo bpm
3 things it can do:
    1)  program sequence
    2)  adjust tone
    3)  change the world
 */
struct Tr808
{
    //1) number of voices
    int numVoices = 11;
    //2) step trigger
    bool stepTrig = true;
    //3) level amount per voice in decibels
    float voiceLevel = -2.3f;
    //4) preset number
    int preset = 12;
    //5) tempo bpm
    int tempo = 135;

    //1) program sequence using an array of engaged steps as an argument
    void programSequence(std::vector<bool> sequence = {true, false, false, false}, bool stepTrig = true);
    //2) adjust tone
    float adjustTone(float knobTurn);
    //3) change the world
    double changeTheWorld(bool musicIsAmazing);
};

/*
Thing 3) Electric Guitar
5 properties:
    1)  volume level
    2)  tone level
    3)  number of strings
    4)  tuning pegs rotation degree
    5)  seymour duncan pickups (bool)
3 things it can do:
    1)  play music
    2)  feedback
    3)  guitar spin
 */
struct ElectricGuitar
{
    //1)  volume level in decibels
    float volume = -0.45f;
    //2)  tone level
    float tone = 12.2f;
    //3)  number of strings
    int strings = 6;
    //4)  tuning pegs rotation degree
    double tunePeg = 23.43;
    //5)  seymour duncan pickups
    bool seymourDuncanPickups = true;

    //1)  play music
    bool playMusic(double tunePeg, float volume = 0.0f, int strings = 6);
    //2)  feedback
    float feedback(float volume, float tone, float ampGain);
    //3)  guitar spin
    bool guitarSpin(bool crowdIsWild);
};

/*
Thing 4) Granular Synth
5 properties:
    1)  grain size
    2)  grain density
    3)  playback position
    4)  varispeed of sample
    5)  random
3 things it can do:
    1)  granulate
    2)  change playback position
    3)  modulate grain size
 */
struct GranularSynth
{
    //1)  grain size in seconds
    float grainSize = 0.6f;
    //2)  grain density(amount of grains played at once)
    int grainDensity = 7;
    //3)  playback position
    float playbackPosition = 0.0;
    //4)  varispeed of sample
    float varispeed = 1.0f;
    //5)  random
    double random = 0.12;

    //1)  granulate
    void granulate(float grainSize, int grainDensity, float playbackPosition, float varispeed, double random);
    //2)  change playback position
    void slide(float playBackPosition, float modulationInput);
    //3)  modulate grain size
    void modGrainSize(float grainSize, float modulationInput);
};

/*
Thing 5) Oscillators
5 properties:
    1)  -12v power consumption
    2)  +12v power consumption
    3)  waveshape value
    4)  output type (sine, saw, waveshaper)
    5)  FM attenuator value
3 things it can do:
    1)  outputs wave
    2)  hard sync
    3)  receives pitch CV
 */
struct Oscillators
{
    //1)  -12v power consumption in mA
    int negativeTwelvePower = 40;
    //2)  +12v power consumption in mA
    int positiveTwelvePower = 30;
    //3)  waveshape value
    float waveshape = 12.4f;
    //4)  output type (sine, saw, waveshaper)
    int outputType = 2;
    //5)  FM attenuator value
    float fmAttenuator = 0.46f;

    //1)  outputs wave
    bool outputWave(int negativeTwelvePower, int positiveTwelvePower);
    //2)  hard sync
    void hardSync(float inputSignal, bool hardSyncOnOff);
    //3)  receives pitch CV
    void receivePitchCV(float inputVoltage, float fmAttenuator);
};

/*
Thing 6) Filters
5 properties:
    1)  filter type (HP, LP, BP)
    2)  FM attenuator value
    3)  cutoff value
    4)  resonance value
    5)  gain value
3 things it can do:
    1)  filter audio
    2)  track 1v/oct
    3)  change filter cutoff
 */
struct Filters
{
    //1)  filter type (HP, LP, BP)
    int filterType = 1;
    //2)  FM attenuator value
    float fmAttenuator = 43.23f;
    //3)  cutoff value
    float cutoff = 56.23f;
    //4)  resonance value
    float resonance = 15.54f;
    //5)  gain value +dB
    float gain = 12.3f;

    //1)  filter audio
    void filter(int filterType, float fmAttenuator, float cutoff, float resonance, float gain);
    //2)  track 1v/oct
    void trackPitch(float cutoff, float fmAttenuator);
    //3)  change filter cutoff
    void modFilter(float cutoff, float fmAttenuator);
};

/*
Thing 7) Envelopes
5 properties:
    1)  attack time
    2)  decay time
    3)  sustain level
    4)  release time
    5)  hold time
3 things it can do:
    1)  output CV
    2)  receive gate/trigger
    3)  engage cycle mode
 */
struct Envelopes FIXME: is this representing ONE envelope or several envelopes?
{
    //1)  attack time in ms
    int attack = 243;
    //2)  decay time in ms
    int decay = 501;
    //3)  sustain level in percentage
    float sustain = 0.67f;
    //4)  release time in ms
    int release = 684;
    //5)  hold time in ms
    int hold = 43;

    //1)  output CV
    float outputCV(bool powerOn, bool gateHigh);
    //2)  receive gate/trigger
    bool receive(bool cycleModeOnOff = false);
    //3)  engage cycle mode
    bool cycleMode(bool switchPosition);
};

/*
Thing 8) VCAs
5 properties:
    1)  number of audio inputs
    2)  number of cv inputs
    3)  cascading cv inputs (bool)
    4)  boost switch
    5)  number of audio outputs
3 things it can do:
    1)  receive cv
    2)  output audio/cv
    3)  mute output
 */
struct VCAs FIXME: is this representing ONE VCA or multiple VCAs?
{
    //1)  number of audio inputs
    int audioInputs = 4;
    //2)  number of cv inputs
    int cvInputs = 4;
    //3)  cascading cv inputs
    bool cascadingCV = true;
    //4)  boost switch
    bool boostSwitch = true;
    //5)  number of audio outputs
    int audioOutputs = 4;


    //1)  receive cv
    void receiveCV(int cvInputs);
    //2)  output audio/cv
    void output();
    //3)  mute output
    void mute(bool muteSwitch);
};

/*
Thing 9) CV Sequencer
5 properties:
    1)  number of channels
    2)  channel output level
    3)  number of steps
    4)  clock mode(slave or master)
    5)  scale select (int)
3 things it can do:
    1)  output cv
    2)  receive clock
    3)  arpeggiate steps
 */
struct CVSequencer
{
    //1)  number of channels
    int cvChannels = 8;
    //2)  channel output level
    float outputLevel = 2.3f;
    //3)  number of steps
    int steps = 16;
    //4)  clock mode(slave or master)
    bool clockMode = false;
    //5)  scale select
    int scale = 2;

    //1)  output cv
    bool output(bool powerOn);
    //2)  receive clock
    bool receiveClock(bool clockMode);
    //3)  arpeggiate steps
    bool arp(bool stepsOn, std::vector<int> stepOrder[]);
};

/*
Thing 10) Modular Synth
5 properties:
    1)  oscillators
    2)  filters
    3)  envelopes
    4)  VCAs    
    5)  CV Sequencer
3 things it can do:
    1)  changes pitch
    2)  cross modulates
    3)  modulate decay time of AD envelope
 */
struct ModularSynth
{
    //1)  oscillators
    Oscillators oscillators;
    //2)  filters
    Filters flters;
    //3)  envelopes
    Envelopes envelopes;
    //4)  VCAs    
    VCAs vcas;
    //5)  CV Sequencer
    CVSequencer cvsequencer;

    struct Module
    {
        int negativeTwelvePower;
        int positiveTwelvePower;
        int hp;
        bool threeU = true;
        int numberOfInputs;

        void outputVoltage(int negativeTwelvePower, int positiveTwelvePower);
        void receiveVoltage();
        void processVoltage(float inputValues);
    };

    //1)  changes pitch
    void changePitch(void receivePitchCV(float inputVoltage, float fmAttenuator));
    //2)  cross modulates
    void crossMod(Envelopes);
    //3)  modulate decay time of AD envelope
    void modDecayEnv(int decay);
};

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
