airport: main.o crewMember.o crewMembers.o aircraft.o aircrafts.o flight.o flights.o
	g++ -o airport main.o crewMember.o crewMembers.o aircraft.o aircrafts.o flight.o flights.o

main.o: main.cpp crewMembers.o aircrafts.o flights.o 
	g++ -c main.cpp

crewMember.o: crewMember.cpp crewMember.h pilot.cpp pilot.h copilot.cpp copilot.h LilTimmyDropTable.cpp LilTimmyDropTable.h
	g++ -c crewMember.cpp pilot.cpp copilot.cpp LilTimmyDropTable.cpp

crewMembers.o: crewMembers.cpp crewMembers.h crewMember.cpp crewMember.h
	g++ -c crewMembers.cpp

aircraft.o: aircraft.cpp aircraft.h
	g++ -c aircraft.cpp

aircrafts.o: aircrafts.cpp aircrafts.h aircraft.cpp aircraft.h
	g++ -c aircrafts.cpp

flight.o: flight.cpp flight.h
	g++ -c flight.cpp

flights.o: flights.cpp flights.h flight.cpp flight.h
	g++ -c flights.cpp