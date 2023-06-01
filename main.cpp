/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */

/*
 copied UDT 1:
 */
struct Castle
{
    int numberOfGates;
    std::string nameOfKing;
    std::string nameOfQueen;
    float amountOfTaxesCollected;
    bool isAtWar;

    Castle();
    ~Castle();

    struct FarmlandRevenue
    {
        int totalRevenue = 2500;
        int arces {65}, numberOfWorkers {120};
        float wheatSalePricePerKG {1.8f};
        std::string type {"Cereals and Grains"};
        bool isInDrought {false};

        FarmlandRevenue();
        ~FarmlandRevenue();

        void sellWheat(int wheatStockLevel, float currentMarketPrice, float amountToSell);
        float displayCurrentTurnover(int totalWorkers, int farmlandArea, float currentMarketPrice, float previousMarketPrice);
        void floodFarmlands(int areaToFlood, float amountOfFlooding, bool isIndrought);
        void hireNewWorkers(int startWorkers, int revenueThreshold);
    };

    float reportCollectTaxes(float collectTaxes, FarmlandRevenue farmlandIncome);
    void openCastleGates(int numberOfGatesClosed);
    std::string announceOrders(std::string orders);
    void fireSignalArrow(int startArrows, int targetHits);
};

Castle::Castle() : numberOfGates(8), nameOfKing("Edward"), nameOfQueen("Magda"), amountOfTaxesCollected(300.f), isAtWar(true)
{
    // Castle class constructor
    std::cout << "Castle being constructed!\n";  
}

Castle::~Castle()
{
    // Castle class deconstructor
    std::cout << "Castle being deconstructed\n";
}

Castle::FarmlandRevenue::FarmlandRevenue()
{
    // FarmlandRevenue constructor
    std::cout << "FarmlandRevenue being constructed!\n";
}

Castle::FarmlandRevenue::~FarmlandRevenue()
{
    // FarmlandRevenue deconstructor
    std::cout << "FarmlandRevenue being deconstructed!\n";
}

void Castle::FarmlandRevenue::hireNewWorkers(int startWorkers, int revenueThreshold)
{
    int worker = (numberOfWorkers / numberOfWorkers);
    int workers = startWorkers;
    int revenuePerWorkerPerDay = (worker * 10);
    int revenue = workers * revenuePerWorkerPerDay;

    while (revenue < revenueThreshold) 
    {
        ++workers;
        revenue = workers * revenuePerWorkerPerDay;
        if (revenue >= revenueThreshold) 
        {
            std::cout << "Hired " << workers << " workers to reach the revenue threshold.\n";
            return;
        }
    }
    std::cout << "The initial number of workers already generates enough revenue.\n";
}

void Castle::fireSignalArrow(int startArrows, int targetHits) 
{
    int arrows = startArrows;
    int hits = 0;

    while (arrows > 0 && hits < targetHits) 
    {
        --arrows;

        int hitTarget = rand() % 2;
        
        if (hitTarget == 1) 
        {
            ++hits;
            std::cout << "Target hit! Total hits: " << hits << "\n";
        } 
        else 
        {
            std::cout << "Missed. Remaining arrows: " << arrows << "\n";
        }
        if (hits >= targetHits) 
        {
            std::cout << "Target hits threshold reached with " << arrows << " arrows left.\n";
            return;
        }
    }
    
    if (arrows == 0) 
    {
        std::cout << "Out of arrows. Total hits: " << hits << "\n";
    }
}

void Castle::FarmlandRevenue::sellWheat(int wheatStockLevel, float currentMarketPrice, float amountToSell)
{
    int availableStock = wheatStockLevel - 100;
    
    if (availableStock < 100)
    {
        std::cout << "Stock levels too low\n";
    }
    else
    {
        std::cout << "Stock levels OK\n";
        std::cout << "Market price: " << currentMarketPrice << "\n";
        float estimatedSale = currentMarketPrice * amountToSell;
        std::cout << "Expected sale price: " << estimatedSale << "\n";
    }
}

float Castle::FarmlandRevenue::displayCurrentTurnover(int totalWorkers, int farmlandArea, float currentMarketPrice, float previousMarketPrice)
{
    int workForceOverArea = totalWorkers + farmlandArea / 2;
    std::cout << "Workforce turnover per acre: " << workForceOverArea << std::endl;
    float marketEstimation = currentMarketPrice - previousMarketPrice * 0.2f;
            
    return marketEstimation;
}

void Castle::FarmlandRevenue::floodFarmlands(int areaToFlood, float amountOfFlooding, bool isIndrought)
{
    if(isIndrought)
    {
        std::cout << "Select area to flood " << areaToFlood << "\n";
        std::cout << "Adjust flood level " << amountOfFlooding << "\n";       
    }
    else
    {
        std::cout << "Flooding not required\n";
    }
}

float Castle::reportCollectTaxes(float collectTaxes, FarmlandRevenue farmlandIncome)
{
    float taxTotalIncome = 0.f;
    float currentlyTaxed = collectTaxes * 20;
    float produceTax = farmlandIncome.displayCurrentTurnover(45, 12, 12.f, 10.f);

    std::cout << "Reporting tax collection my lord!\n";
    
    return taxTotalIncome = currentlyTaxed + produceTax;
}

void Castle::openCastleGates(int numberOfGatesClosed)
{
    if (numberOfGatesClosed <= 0)
    {
        std::cout << "All gates are already open.\n";
    }
    else
    {
        std::cout << "Opening " << numberOfGatesClosed << " gates...\n";
        std::cout << "Gates opened successfully!\n";
    }
}

std::string Castle::announceOrders(std::string orders)
{
    std::cout << "Here are the orders: " << orders << "\n";
    return orders;
}

/*
 copied UDT 2:
 */
struct RolandTB303
{
    int stepSequencer {16}, modeDial {10}, tempoDial {32};
    float cutoffFrequencyFilterKnob {750.f}, volumeKnob {-18.f};

    RolandTB303();
    ~RolandTB303();

    struct SavePattern
    {
        int numberOfSteps, tempoNumberSelected, loopCount;
        bool exportingToExternalDisk;
        float randomisationAmount;

        SavePattern();
        ~SavePattern();

        void savingSequence(int stepSize, int numberOfStepsEnabled, int numberOfLoops, int tempo);
        bool savingToExternal(int stepCount, std::string fileType = "TB303.p");
        void displaySavingProgress(int timeRemaining, float savingRate);
        void recallPattern(char X);
    };

    void programSequence(RolandTB303 sequence);
    void filterSignal(float cutoffFrequency);
    float tempoAdjust(RolandTB303 tempo);
    int syncMidi(int midiNotesIn);
};

RolandTB303::RolandTB303()
{
    // RolandTB303 constructor
    std::cout << "RolandTB303 being constructed!\n";  
}

RolandTB303::~RolandTB303()
{
    // RolandTB303 deconstructor
    std::cout << "RolandTB303 being deconstructed.\n";
}

RolandTB303::SavePattern::SavePattern() : numberOfSteps(24), tempoNumberSelected(12), loopCount(8), exportingToExternalDisk(true), randomisationAmount(8.5f)
{
    // Constructor
    std::cout << "SavePattern being constructed!\n";
}

RolandTB303::SavePattern::~SavePattern()
{
    // Deconstructor
    std::cout << "SavePattern being deconstructed!\n";
}
    
void RolandTB303::SavePattern::recallPattern(char X)
{    
    if (X == 'A')
    {
        std::cout << "Loading previous sequence... " << X << "\n";
        int sequenceMemory = 25;
        std::cout << "Sequence step total: " << sequenceMemory << "\n";
        
        for (int seq = 0; seq < 25; ++seq)
        {
            std::cout << "Step " << (seq + 1) << " loaded\n";
        }
    }
    else if (X == 'B')
    {
        std::cout << "Loading previous sequence... " << X << "\n";
        int sequenceMemory = 15;
        std::cout << "Sequence step total: " << sequenceMemory << "\n";
        
        for (int seq = 0; seq < 25; ++seq)
        {
            std::cout << "Step " << (seq + 1) << " loaded\n";
        }   
    }
    else if (X == 'C')
    {
        std::cout << "Loading previous sequence... " << X << "\n";
        int sequenceMemory = 41;
        std::cout << "Sequence step total: " << sequenceMemory << "\n";
        
        for (int seq = 0; seq < 25; ++seq)
        {
            std::cout << "Step " << (seq + 1) << " loaded\n";
        } 
    }
    else
    {
        std::cout << "Loading previous sequence ERROR...\n" << "Please try again...\n";
    }
}

int RolandTB303::syncMidi(int midiNotesIn)
{
    int totalMidiCount = midiNotesIn;
    
    for (int note = 0; note < midiNotesIn; ++note)
    {
        std::cout << "Syncing MIDI...\n";
        
        if (midiNotesIn != 0)
        {
            std::cout << "MIDI sync progress " << (note + 1) << " out of " << midiNotesIn << " \n" << "MIDI notes remaining before full sync " << (totalMidiCount -= 1) << " \n";
        }
    }
    return totalMidiCount;
}

void RolandTB303::SavePattern::savingSequence(int stepSize, int numberOfStepsEnabled, int numberOfLoops, int tempo)
{
    int savedSeq = stepSize + numberOfStepsEnabled + numberOfLoops + tempo;
    std::cout << "Saving sequence..." << savedSeq << "\n";
}

bool RolandTB303::SavePattern::savingToExternal(int stepCount, std::string fileType)
{
    if(stepCount > 0)
    {
        std::cout << "Exporting " << fileType << "\n";
        return true;
    }
    std::cout << "Export error, no steps" << "\n";
    return false;
}

void RolandTB303::SavePattern::displaySavingProgress(int timeRemaining, float savingRate)
{
    std::cout << "Time remaining: " << timeRemaining << " (secs)\n";
    std::cout << "saving data speed: " << savingRate << " kbps\n";
}

void RolandTB303::programSequence(RolandTB303 sequence)
{
    int displaySequenceCount = sequence.stepSequencer;
    std::cout << "Number of steps: " << displaySequenceCount << "\n";
}

void RolandTB303::filterSignal(float cutoffFrequency)
{
    std::cout << "Filter CutOff: " << cutoffFrequency << "Hz\n";
}

float RolandTB303::tempoAdjust(RolandTB303 tempo)
{    
    if (tempo.tempoDial > 0)
    {
        std::cout << "Tempo has been changed\n";
        return 15.f;
    }
    std::cout << "No tempo changes here...\n";
    return 1.f;
}
/*
 copied UDT 3:
 */
struct MidiKeyboard
{
    int numberOfKeys, numberOfKnobs, numberOfMPCPads;
    double pitchControlRange;
    char modeSelection;

    MidiKeyboard();
    ~MidiKeyboard();

    double adjustPitch(MidiKeyboard pitchChange);
    void isKeyPressed();
    float padHitAmount(MidiKeyboard padNumber);
    void ledLightDemoMode(std::string onOff);
};

MidiKeyboard::MidiKeyboard() : numberOfKeys(25), numberOfKnobs(16), numberOfMPCPads(4), pitchControlRange(300000.0), modeSelection('Y')
{
    // Constructor
    std::cout << "MidiKeyboard being constructed!\n";  
}

MidiKeyboard::~MidiKeyboard()
{
    // Deconstructor
    std::cout <<"MidiKeyboard being deconstructed!\n";
}
    
void MidiKeyboard::ledLightDemoMode(std::string onOff)
{
    int totalLedsOnKeyboard = 1;
    
    if (onOff == "on")
    {
        for (int led = 0; led < totalLedsOnKeyboard; ++led)
        {
            std::cout << "**\n";
            std::cout << "     **\n";
            std::cout << "          **\n";
            std::cout << "               **\n";
            std::cout << "   PROGRAMMING      **\n";
            std::cout << "   FOR                   **\n";
            std::cout << "   MUSICIANS                  **\n";
            std::cout << "   IS                    **\n";
            std::cout << "   GREAT!           **\n";
            std::cout << "               **\n";
            std::cout << "          **\n";
            std::cout << "     **\n";
            std::cout << "**\n";
        }
    }
    else
    {
         std::cout << "*BLINK* please enter ""on"" for light demo\n";
    }
}

double MidiKeyboard::adjustPitch(MidiKeyboard pitchChange)
{    
    double adjustedPitch = pitchControlRange + pitchChange.pitchControlRange;

    std::cout << "Pitch adjusting!\n";

    return adjustedPitch;
}

void MidiKeyboard::isKeyPressed()
{
    std::cout << "Key input detected\n";
}

float MidiKeyboard::padHitAmount(MidiKeyboard padNumber)
{
    std::cout << "Pad number: " <<padNumber.numberOfMPCPads << "\n";
    std::cout << "BOY you hitting that pad haaaaard!!!\n";
    return 10.f;
}

/*
 new UDT 4:
 with 2 member functions
 */

/*
 new UDT 5:
 with 2 member functions
 */

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
