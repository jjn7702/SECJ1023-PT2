#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Custom exception class for invalid time and date
class InvalidDateTimeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid date or time format.";
    }
};

// Function to validate date (YYYY-MM-DD) format
bool isValidDate(const string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    int year, month, day;
    try {
        year = stoi(date.substr(0, 4));
        month = stoi(date.substr(5, 2));
        day = stoi(date.substr(8, 2));
    } catch (...) {
        return false;
    }
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    return true;
}

// Function to validate time (HH:MM) format
bool isValidTime(const string& time) {
    if (time.length() != 5 || time[2] != ':') {
        return false;
    }
    int hour, minute;
    try {
        hour = stoi(time.substr(0, 2));
        minute = stoi(time.substr(3, 2));
    } catch (...) {
        return false;
    }
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        return false;
    }
    return true;
}

//Module 1 :  Sleep Data
// Sleep Data Class
class SleepData {
private:
    string timestamp;
    double duration;
    double deepSleepDuration;
    double lightSleepDuration;
    double REMduration;

public:
    SleepData(string t, double d, double ds, double ls, double rem)
        : timestamp(t), duration(d), deepSleepDuration(ds), lightSleepDuration(ls), REMduration(rem) {}

    string getTimestamp() const { return timestamp; }
    double getDuration() const { return duration; }
    double getDeepSleepDuration() const { return deepSleepDuration; }
    double getLightSleepDuration() const { return lightSleepDuration; }
    double getREMduration() const { return REMduration; }
};

// Sleep Session Class
class SleepSession {
private:
    string sessionId;
    string startTime;
    string endTime;
    vector<SleepData> sleepData;

public:
    SleepSession(string id, string start, string end, vector<SleepData> data)
        : sessionId(id), startTime(start), endTime(end), sleepData(data) {}

    double getSessionDuration() const {
        double totalDuration = 0;
        for (const auto& data : sleepData) {
            totalDuration += data.getDuration();
        }
        return totalDuration;
    }

    vector<SleepData> getSleepData() const { return sleepData; }
};

//Module 2 : Sleep Analysis
// Sleep Quality Assessment Class
class SleepQualityAssessment {
private:
    double qualityScore;
    string description;

public:
    SleepQualityAssessment(double score, string desc)
        : qualityScore(score), description(desc) {}

    double getQualityScore() const { return qualityScore; }
    string getDescription() const { return description; }
};

// Sleep Cycle Analyzer Class
class SleepCycleAnalyzer {
public:
    void analyzeSleep(const vector<SleepSession>& sessions) {
        cout << "Analyzing sleep data..." << endl;
        for (const auto& session : sessions) {
            cout << "Session Duration: " << fixed << setprecision(2) << session.getSessionDuration() << " hours" << endl;
        }
    }

    SleepQualityAssessment* qualityAssessment(const vector<SleepSession>& sessions) const {
        double totalScore = 0;
        int dataCount = 0;

        for (const auto& session : sessions) {
            for (const auto& data : session.getSleepData()) {
                double sessionQuality = 0;
                sessionQuality += data.getDeepSleepDuration() * 1.5; 
                sessionQuality += data.getLightSleepDuration();
                sessionQuality += data.getREMduration() * 1.2; 
                totalScore += sessionQuality;
                ++dataCount;
            }
        }

        double averageScore = (dataCount > 0) ? (totalScore / dataCount) : 0;
        string description;

        if (averageScore >= 8.0) {
            description = "Excellent";
        } else if (averageScore >= 6.0) {
            description = "Good";
        } else if (averageScore >= 4.0) {
            description = "Fair";
        } else {
            description = "Poor";
        }

        return new SleepQualityAssessment(averageScore, description);
    }
};

//Module 3 : Sleep Summary
// Sleep Report Class
class SleepReport {
private:
    string reportDate;
    string summary;
    string recommendations;

public:
    SleepReport() : reportDate("2024-06-01") {}

    void generateSummary(const vector<SleepSession>& sessions) {
        summary = "Summary of sleep report:\n";
        double totalDuration = 0;
        double totalDeepSleep = 0;
        double totalLightSleep = 0;
        double totalREM = 0;

        for (const auto& session : sessions) {
            for (const auto& data : session.getSleepData()) {
                totalDuration += data.getDuration();
                totalDeepSleep += data.getDeepSleepDuration();
                totalLightSleep += data.getLightSleepDuration();
                totalREM += data.getREMduration();
            }
        }

        double averageDuration = totalDuration / sessions.size();
        double averageDeepSleep = totalDeepSleep / sessions.size();
        double averageLightSleep = totalLightSleep / sessions.size();
        double averageREM = totalREM / sessions.size();

        summary += "Average Sleep Duration: " + to_string(averageDuration) + " hours\n";
        summary += "Average Deep Sleep Duration: " + to_string(averageDeepSleep) + " hours\n";
        summary += "Average Light Sleep Duration: " + to_string(averageLightSleep) + " hours\n";
        summary += "Average REM Duration: " + to_string(averageREM) + " hours\n";
    }

   void generateRecommendations(const vector<SleepSession>& sessions) {
    recommendations = "Recommendations for better sleep:\n";

    double totalDuration = 0;
    for (const auto& session : sessions) {
        totalDuration += session.getSessionDuration();
    }
    double averageDuration = totalDuration / sessions.size();

    if (averageDuration < 7.0) {
        recommendations += "- Aim for at least 7 hours of sleep per night.\n";
    } else if (averageDuration > 9.0) {
        recommendations += "- Aim for 7-9 hours of sleep per night. Sleeping more than 9 hours can lead to sleep inertia and negatively impact your daily routine.\n";
    } else {
        recommendations += "- Your sleep duration is within the recommended range of 7-9 hours. Keep up the good habits!\n";
    }
}

    void printReport(const vector<SleepSession>& sessions) {
        generateSummary(sessions);
        generateRecommendations(sessions);
        cout << "Sleep Report - " << reportDate << endl;
        cout << summary << endl;
        cout << recommendations << endl;
    }

    void printRecommendations() {
        cout << recommendations << endl;
    }
};

// Forward declaration of User class
class User;

class Suggestion {
protected:
    string suggestionText;

public:
    virtual string provideSuggestion() const = 0;
};

class ImprovementPlan : public Suggestion {
private:
    string planDetails;

public:
    ImprovementPlan(string details) : planDetails(details) {}

    void createPlan(const User& user);

    string provideSuggestion() const override {
        return "Improvement Plan: " + planDetails;
    }
};

//Module 4 : User
// User Class
class User {
private:
    string userID;
    string name;
    int age;
    double weight;
    double height;
    vector<SleepSession> sleepSessions;
    SleepReport* sleepReport;
    SleepQualityAssessment* sleepQualityAssessment;
    vector<Suggestion*> suggestions;
    SleepCycleAnalyzer sleepCycleAnalyzer;

public:
    User(string id, string n, int a, double w, double h)
        : userID(id), name(n), age(a), weight(w), height(h), sleepQualityAssessment(nullptr), sleepReport(nullptr) {}

    void updateProfile(string n, int a, double w, double h) {
        name = n;
        age = a;
        weight = w;
        height = h;
    }
    
    string getName() const { return name; }
    int getAge() const { return age; }
    double getWeight() const { return weight; }
    double getHeight() const { return height; }

    void addSleepSession(const SleepSession& session) {
        sleepSessions.push_back(session);
    }

    void analyzeSleep() {
        sleepCycleAnalyzer.analyzeSleep(sleepSessions);
    }

    void qualityAssessment() {
        if (sleepQualityAssessment) {
            delete sleepQualityAssessment;
        }
        sleepQualityAssessment = sleepCycleAnalyzer.qualityAssessment(sleepSessions);
    }

    void generateImprovementPlan() {
        suggestions.clear();
        if (sleepQualityAssessment) {
            ImprovementPlan* plan = new ImprovementPlan("Generated Plan");
            plan->createPlan(*this);
            suggestions.push_back(plan);
        }
    }

   void generateReport() {
    if (sleepReport) {
        delete sleepReport;
    }
    sleepReport = new SleepReport();
    sleepReport->printReport(sleepSessions);
    qualityAssessment(); 
}


    void displaySleepQuality() const {
        if (sleepQualityAssessment) {
            cout << "Sleep Quality Score: " << fixed << setprecision(2) << sleepQualityAssessment->getQualityScore() << endl;
            cout << "Description: " << sleepQualityAssessment->getDescription() << endl;
        }
    }

    void displaySuggestions() const {
        for (const auto& suggestion : suggestions) {
            cout << suggestion->provideSuggestion() << endl;
        }
    }

    ~User() {
        if (sleepQualityAssessment) {
            delete sleepQualityAssessment;
        }
        for (auto suggestion : suggestions) {
            delete suggestion;
        }
        delete sleepReport;
    }

    friend class ImprovementPlan;
};

void ImprovementPlan::createPlan(const User& user){
    const SleepQualityAssessment* assessment = user.sleepQualityAssessment;

    if (assessment) {
        double score = assessment->getQualityScore();
        planDetails = "Generated Plan based on your sleep quality assessment:\n";

        // Suggestions based on overall sleep quality score <https://www.ncbi.nlm.nih.gov/pmc/articles/PMC6286721/>
        if (score < 4.0) {
            planDetails += "- Your sleep quality score is low. Consider consulting a healthcare provider for potential sleep disorders such as insomnia or sleep apnea.\n";
            planDetails += "- Focus on improving sleep quality through relaxation techniques such as meditation or deep breathing exercises before bedtime to improve your score.\n";
        } else if (score < 6.0) {
            planDetails += "- Your sleep quality score is fair. Focus on improving sleep quality through relaxation techniques such as meditation or deep breathing exercises before bedtime to improve your score.\n";
        } else {
            planDetails += "- Your sleep quality score is good. Keep up the good habits!\n";
        }

        // Suggestions based on sleep duration <https://www.healthline.com/health/how-much-deep-sleep-do-you-need#stages-of-sleep>
        double totalDuration = 0;
        for (const auto& session : user.sleepSessions) {
            for (const auto& data : session.getSleepData()) {
                totalDuration += data.getDuration();
            }
        }

        double averageSleepDuration = totalDuration / user.sleepSessions.size();
        planDetails += "- Your average sleep duration is " + to_string(averageSleepDuration) + " hours.\n";
        if (averageSleepDuration < 7.0) {
            planDetails += "- Aim for at least 7-9 hours of sleep per night to improve overall sleep quality.\n";
        } else {
            planDetails += "- Your average sleep duration is excellent. Keep up the good habits!\n";
        }

        // Suggestions based on sleep stages
        double totalDeepSleep = 0;
        double totalLightSleep = 0;
        double totalREM = 0;
        double totalSleep = 0;

        for (const auto& session : user.sleepSessions) {
            for (const auto& data : session.getSleepData()) {
                totalDeepSleep += data.getDeepSleepDuration();
                totalLightSleep += data.getLightSleepDuration();
                totalREM += data.getREMduration();
                totalSleep += data.getDuration();
            }
        }

        double deepSleepPercentage = (totalDeepSleep / totalSleep) * 100;
        double lightSleepPercentage = (totalLightSleep / totalSleep) * 100;
        double REMPercentage = (totalREM / totalSleep) * 100;

        planDetails += "- Your average deep sleep percentage is " + to_string(deepSleepPercentage) + "%.\n";
        if (averageSleepDuration < 7.0) {
            planDetails += "  - It's difficult to get quality sleep with such a short sleep duration. Aim for at least 7-9 hours of sleep per night to improve overall sleep quality.\n";
        } else if (deepSleepPercentage < 20 ||deepSleepPercentage > 25) {
            planDetails += "  - Consider creating a consistent sleep schedule, reducing caffeine intake, and ensuring a dark, quiet, and cool sleep environment to improve deep sleep.\n";
            planDetails += "  - Learn relaxation techniques such as progressive muscle relaxation, mindfulness meditation, or deep breathing exercises from websites like <https://www.headspace.com/> or <https://www.calm.com/> to improve deep sleep.\n";
        } else {
            planDetails += "  - Your deep sleep percentage is good. Keep up the good habits!\n";
        }

        planDetails += "- Your average light sleep percentage is " + to_string(lightSleepPercentage) + "%.\n";
        if (averageSleepDuration < 7.0) {
            planDetails += "  - It's difficult to get quality sleep with such a short sleep duration. Aim for at least 7-9 hours of sleep per night to improve overall sleep quality.\n";
        } else if (lightSleepPercentage < 50) {
            planDetails += "  - Consider engaging in regular physical activity, maintaining a comfortable and supportive mattress and pillows, and learning about sleep-conducive habits and routines to improve light sleep.\n";
            planDetails += "  - Learn about the importance of light sleep and how to improve it from websites like <https://www.sleepfoundation.org/> or <https://www.sleep.org/>.\n";
        } else {
            planDetails += "  - Your light sleep percentage is good. Keep up the good habits!\n";
        }

         planDetails += "- Your average REM sleep percentage is " + to_string(REMPercentage) + "%.\n";
        if (averageSleepDuration < 7.0) {
            planDetails += "  - It's difficult to get quality sleep with such a short sleep duration. Aim for at least 7-9 hours of sleep per night to improve overall sleep quality.\n";
        } else if (REMPercentage < 20 || REMPercentage > 25 ) {
            planDetails += "  - Consider reducing stress through mindfulness practices, avoiding alcohol and heavy meals before bedtime, and learning about stress-reducing techniques and sleep tips to improve REM sleep.\n";
            planDetails += "  - Learn about the importance of REM sleep and how to improve it from websites like <https://www.verywellmind.com/> or <https://www.healthline.com/>.\n";
        } else {
            planDetails += "  - Your REM sleep percentage is good. Keep up the good habits!\n";
        }
    }
}

int main() {
    cout << fixed << setprecision(2);
    cout << "========== Welcome to the Sleep Analyzer System ===========" << endl;
    
    string name;
    int age;
    double weight, height;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your weight (in kg): ";
    cin >> weight;

    cout << "Enter your height (in cm): ";
    cin >> height;

    User user("user1", name, age, weight, height);

  cout << "\n\n=== User Profile ===" << endl;
    cout << "Name: " << user.getName() << endl;
    cout << "Age: " << user.getAge() << endl;
    cout << "Weight: " << user.getWeight() << " kg" << endl;
    cout << "Height: " << user.getHeight() << " cm" << endl;
    
char guidance;
        cout << "Do you need guidance on entering sleep data? (y/n): ";
        cin >> guidance;

        if (guidance == 'y' || guidance == 'Y') {
            cout << "If you don't have sleep data, you can estimate the total sleep duration and stages based on your experience." << endl;
            cout << "To estimate sleep stages manually, determine your bedtime, wake time, and how rested you feel upon waking." << endl;
            cout << "You can then calculate the total sleep duration and estimate time spent in deep sleep, light sleep, and REM sleep." << endl << endl;
        }
        cout << "Please enter details for the sleep session:" << endl;
    int sessionCount;
    cout << "\nEnter number of sleep sessions: ";
    cin >> sessionCount;

    for (int i = 0; i < sessionCount; ++i) {
        string sessionId, date, startTime, endTime;
        cout << "Enter Session ID: ";
        cin >> sessionId;

        while (true) {
            try {
                cout << "Enter Date (YYYY-MM-DD): ";
                cin >> date;
                if (!isValidDate(date)) {
                    throw InvalidDateTimeException();
                }
                break;
            } catch (const InvalidDateTimeException& e) {
                cout << e.what() << " Please re-enter a valid date." << endl;
            }
        }

        while (true) {
            try {
                cout << "Enter Start Time (HH:MM): ";
                cin >> startTime;
                if (!isValidTime(startTime)) {
                    throw InvalidDateTimeException();
                }
                break;
            } catch (const InvalidDateTimeException& e) {
                cout << e.what() << " Please re-enter a valid start time." << endl;
            }
        }

        while (true) {
            try {
                cout << "Enter End Time (HH:MM): ";
                cin >> endTime;
                if (!isValidTime(endTime)) {
                    throw InvalidDateTimeException();
                }
                break;
            } catch (const InvalidDateTimeException& e) {
                cout << e.what() << " Please re-enter a valid end time." << endl;
            }
        }

        string startDateTime = date + " " + startTime;
        string endDateTime = date + " " + endTime;

       int sleepDataCount;
        cout << "Enter number of sleep data entries for this session: ";
        cin >> sleepDataCount;


        vector<SleepData> sleepDataEntries;
        for (int j = 0; j < sleepDataCount; ++j) {
            string timestamp;
            double duration;
            cout << "Enter Timestamp (HH:MM): ";
            cin >> timestamp;
            cout << "Enter Duration (hours): ";
            cin >> duration;

            // For simplicity in manual entry, let's assume rough estimates for sleep stages based on <https://www.ncbi.nlm.nih.gov/books/NBK526132/>
             double totalSleepTime;
             cout << "Enter Total Sleep Time (hours): ";
             cin >> totalSleepTime;

             double lightSleepDuration = totalSleepTime * 0.50; // 50% of total sleep time (N1 and N2)
             double deepSleepDuration = totalSleepTime * 0.25; // 25% of total sleep time (N3)
             double REMduration = totalSleepTime * 0.25; // 25% of total sleep time

            sleepDataEntries.emplace_back(timestamp, duration, deepSleepDuration, lightSleepDuration, REMduration);
        }

        SleepSession session(sessionId, startDateTime, endDateTime, sleepDataEntries);
        user.addSleepSession(session);
    }

    cout << "\n\n=== Sleep Data Entry Complete ===" << endl;

    cout << "\n=== Analyzing Sleep Data ===" << endl;
    user.analyzeSleep();

    cout << "\n\n=== Sleep Report ===" << endl;
    user.generateReport();

    cout << "\n\n=== Sleep Quality Assessment ===" << endl;
    user.qualityAssessment();
    user.displaySleepQuality();

    cout << "\n\n=== Improvement Plan ===" << endl;
    user.generateImprovementPlan();
    user.displaySuggestions();

    return 0;
}