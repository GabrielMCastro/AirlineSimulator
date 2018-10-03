all: main.o Plane.o PlaneCollection.o CrewMember.o CrewMemberCollection.o Flight.o FlightCollection.o Pilot.o CoPilot.o Cabin.o 
	g++ main.o Plane.o PlaneCollection.o CrewMember.o Pilot.o CoPilot.o Cabin.o CrewMemberCollection.o Flight.o FlightCollection.o -o MeanGreenAirlines

main.o: main.cpp
	g++ -c main.cpp -o main.o

Plane.o: Plane.h Plane.cpp
	g++ -c Plane.cpp -o Plane.o

PlaneCollection.o: PlaneCollection.h PlaneCollection.cpp
	g++ -c PlaneCollection.cpp -o PlaneCollection.o

CrewMember.o: CrewMember.h CrewMember.cpp
	g++ -c CrewMember.cpp -o CrewMember.o

Pilot.o: Pilot.h Pilot.cpp
	g++ -c Pilot.cpp -o Pilot.o

CoPilot.o: CoPilot.h CoPilot.cpp
	g++ -c CoPilot.cpp -o CoPilot.o

Cabin.o: Cabin.h Cabin.cpp
	g++ -c Cabin.cpp -o Cabin.o

CrewMemberCollection.o: CrewMemberCollection.h CrewMemberCollection.cpp
	g++ -c CrewMemberCollection.cpp -o CrewMemberCollection.o

Flight.o: Flight.h Flight.cpp
	g++ -c Flight.cpp -o Flight.o

FlightCollection.o: FlightCollection.h FlightCollection.cpp
	g++ -c FlightCollection.cpp -o FlightCollection.o

clean:
	rm *.o
	rm MeanGreenAirlines

clear:
	rm *.dat

nice:
	rm *.o