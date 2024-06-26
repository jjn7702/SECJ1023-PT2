# 1.0  Section A :  project description & analysis and design
Our proposed system is the medication scheduler. The general idea of this system is to develop a system which can be used by individuals who have to take medication on a schedule with the accurate dosage, especially for those who have to take different medications with different dosage at a time. This is an upgraded version of the traditional system that uses labeled containers to alert patients on medicine intake. Instead, this system can be integrated into their device and can be accessed at any time.

Our system objectives are:
Medication scheduling: record prescribed medication details (medication name, shapes, color), shapes and colors are easier way to identify different medication 
Keep track: dosage, timing, routine (before meal/after meal, daily) and progress (e.g. antibiotics take up to 2 weeks only)
Reminder: Alert user the time to take medicine by send notification to make sure user take the medication on time
Secondary assurance: supervision from guardian or personal doctor especially for the elderly, guardian/personal healthcare provider can monitor patient virtually
Portable (system accessible through any electronic device: smart watch/phone): offers the convenience of having all medication information in one place

Overall, the medication scheduler system manages their medications more effectively, helping individuals with better health outcomes and improved quality of life.

On June 23, 2024, we introduced the Medication Scheduler system to Madam Lizawati, who provided encouraging input and constructive feedback. In response, we have included a number of modifications and improvements to our analytical and design process. The modifications are:
Adding database by creating output file to store patient list, patientlist.txt and patient’s medicine history, PatientName_med_history.txt
Hiding password by using getch() and include <conio.h>
Displaying the past and current medicine(s) that students have to take by using time function and include <ctime>

## 1.1 Flowchart
![Flowchart](images/PT2_Proj_Flowchart.png)
## 1.2 UML Class Diagram
![UML_Class_Diagram](images/PT2_Proj_UML.png)
