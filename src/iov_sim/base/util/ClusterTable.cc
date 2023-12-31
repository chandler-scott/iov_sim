/*
 * ClusterTable.cpp
 *
 *  Created on: Jul 24, 2023
 *      Author: chandler
 */

#include "ClusterTable.h"

// Constructor
ClusterTable::ClusterTable(double defaultTimeout) : timeout(defaultTimeout)
{
    setWeights();
}

ClusterTable::ClusterTable(std::string initString, double defaultTimeout)
    : timeout(defaultTimeout)
{
    setWeights();
    fromString(initString);
}

// Set weights for scoring neighbors
void ClusterTable::setWeights(double inRangeWeight, double xVelWeight,
        double yVelWeight, double signalStrWeight, double spdWeight, double accelWeight,
        double decelWeight, double xPosWeight, double yPosWeight, double timeWeight,
        double xDirectionWeight, double yDirectionWeight)
{
    carsInRangeWeight = inRangeWeight;
    xVelocityWeight = xVelWeight;
    yVelocityWeight = yVelWeight;
    signalStrengthWeight = signalStrWeight;
    speedWeight = spdWeight;
    accelerationWeight = accelWeight;
    decelerationWeight = decelWeight;
    xPositionWeight = xPosWeight;
    yPositionWeight = yPosWeight;
    timeWeight = timeWeight;
    xDirectionWeight = xDirectionWeight;
    yDirectionWeight = yDirectionWeight;
}

// Add a row to the table
void ClusterTable::addRow(const NeighborEntry& entry, const char* nodeId) {
    table[nodeId] = entry;
}

// Prune rows from the table based on the given currentTime
void ClusterTable::pruneTable(double currentTime) {
    auto it = table.begin();
    while (it != table.end()) {
        if (currentTime - it->second.timestamp > timeout) {
            it = table.erase(it);
        } else {
            ++it;
        }
    }
}

void ClusterTable::pruneTable(const std::vector<std::string>& clusterNodes) {
    auto it = table.begin();
     while (it != table.end()) {
         const std::string& nodeId = it->first;
         // Check if nodeId is not present in clusterNodes
         if (std::find(clusterNodes.begin(), clusterNodes.end(), nodeId) == clusterNodes.end()) {
             // nodeId not found in clusterNodes, remove the entry from the table
             it = table.erase(it);
         } else {
             ++it;
         }
    }
}

// Calculate metadata for the neighbor table
void ClusterTable::calculateMetadata() {
    double totalCarsInRange = 0.0;
    double totalXVelocity = 0.0;
    double totalYVelocity = 0.0;
    double totalSignalStrength = 0.0;
    double totalSpeed = 0.0;
    double totalAcceleration = 0.0;
    double totalDeceleration = 0.0;
    double totalXPosition = 0.0;
    double totalYPosition = 0.0;
    double totalXDirection = 0.0;
    double totalYDirection = 0.0;
    double totalTimestamp = 0.0;

    for (const auto& entry : table) {
        totalCarsInRange += entry.second.carsInRange;
        totalXVelocity += entry.second.xVelocity;
        totalYVelocity += entry.second.yVelocity;
        totalSignalStrength += entry.second.signalStrength;
        totalSpeed += entry.second.speed;
        totalAcceleration += entry.second.acceleration;
        totalDeceleration += entry.second.deceleration;
        totalXPosition += entry.second.xPosition;
        totalYPosition += entry.second.yPosition;
        totalXDirection += entry.second.xDirection;
        totalYDirection += entry.second.yDirection;
        totalTimestamp += entry.second.timestamp;

    }
    auto size = table.size();

    avgCarsInRange = totalCarsInRange / size;
    avgXVelocity = totalXVelocity / size;
    avgYVelocity = totalXVelocity / size;
    avgSignalStrength = totalSignalStrength / size;
    avgSpeed = totalSpeed / size;
    avgAcceleration = totalAcceleration / size;
    avgDeceleration = totalDeceleration / size;
    avgXPosition = totalXPosition / size;
    avgYPosition = totalYPosition / size;
    avgXDirection = totalXDirection / size;
    avgYDirection = totalYDirection / size;
    avgTimestamp = totalTimestamp / size;

    centricity = 0;
}

// Reset the table to empty
void ClusterTable::scoreNeighbors() {
    score.clear();
    for (const auto& entry : table) {
        score[entry.first] =
                carsInRangeWeight * (avgCarsInRange - entry.second.carsInRange) +
                xVelocityWeight * (avgXVelocity - entry.second.xVelocity) +
                yVelocityWeight * (avgYVelocity - entry.second.yVelocity) +
                signalStrengthWeight * (avgSignalStrength - entry.second.signalStrength) +
                speedWeight * (avgSpeed - entry.second.speed) +
                accelerationWeight * (avgAcceleration - entry.second.acceleration) +
                decelerationWeight * (avgDeceleration - entry.second.deceleration) +
                xPositionWeight * (avgXPosition - entry.second.xPosition) +
                yPositionWeight * (avgYPosition - entry.second.yPosition) +
                xDirectionWeight * (avgXDirection - entry.second.xDirection) +
                yDirectionWeight * (avgYDirection - entry.second.yDirection) +
                timeWeight * (avgTimestamp - entry.second.timestamp);
    }
}

// Convert the ClusterTable object to a string representation
std::string ClusterTable::toString() const
{
    std::string result;

    // Serialize the table entries
    for (const auto& entry : table)
    {
        result += entry.first + ":";
        result += std::to_string(entry.second.carsInRange) + ",";
        result += std::to_string(entry.second.speed) + ",";
        result += std::to_string(entry.second.signalStrength) + ",";
        result += std::to_string(entry.second.xVelocity) + ",";
        result += std::to_string(entry.second.yVelocity) + ",";
        result += std::to_string(entry.second.acceleration) + ",";
        result += std::to_string(entry.second.deceleration) + ",";
        result += std::to_string(entry.second.xPosition) + ",";
        result += std::to_string(entry.second.yPosition) + ",";
        result += std::to_string(entry.second.xDirection) + ",";
        result += std::to_string(entry.second.yDirection) + ",";
        result += std::to_string(entry.second.timestamp) + ",";
        result += "\n";

    }

    return result;
}

// Convert the string representation to a ClusterTable object
void ClusterTable::fromString(const std::string& str)
{
    table.clear();
    score.clear();

    // Split the input string into entries
    std::vector<std::string> entries;
    std::istringstream ss(str);
    std::string entry;
    while (std::getline(ss, entry, '\n'))
    {
        entries.push_back(entry);
    }

    for (const auto& entryStr : entries)
    {
        // Split the entry into its components
        std::istringstream entryStream(entryStr);
        std::string nodeId;
        std::getline(entryStream, nodeId, ':');

        NeighborEntry neighborEntry;

        // Deserialize the properties and set them in the NeighborEntry
        std::string property;
        std::getline(entryStream, property, ',');
        neighborEntry.carsInRange = std::stoi(property); // Convert to int
        std::getline(entryStream, property, ',');
        neighborEntry.speed = std::stod(property);
        std::getline(entryStream, property, ',');
        neighborEntry.signalStrength = std::stod(property);
        std::getline(entryStream, property, ',');
        neighborEntry.xVelocity = std::stod(property);
        std::getline(entryStream, property, ',');
        neighborEntry.yVelocity = std::stod(property);
        std::getline(entryStream, property, ',');
        neighborEntry.acceleration = std::stod(property);
        std::getline(entryStream, property, ',');
        neighborEntry.deceleration = std::stod(property);
        std::getline(entryStream, property, ',');
        neighborEntry.xPosition = std::stod(property);
        std::getline(entryStream, property, ',');
        neighborEntry.yPosition = std::stod(property);
        std::getline(entryStream, property, ',');
        neighborEntry.xDirection = std::stod(property);
        std::getline(entryStream, property, ',');
        neighborEntry.yDirection = std::stod(property);
        std::getline(entryStream, property, ',');
        neighborEntry.timestamp = std::stod(property);

        // Add the NeighborEntry to the table
        table[nodeId] = neighborEntry;
    }
}

std::vector<double> ClusterTable::toList() {
    std::vector<double> values;

    values.push_back(avgCarsInRange);
    values.push_back(avgXVelocity);
    values.push_back(avgYVelocity);
    values.push_back(avgSignalStrength);
    values.push_back(avgSpeed);
    values.push_back(avgAcceleration);
    values.push_back(avgDeceleration);
    values.push_back(avgXPosition);
    values.push_back(avgYPosition);
    values.push_back(avgXDirection);
    values.push_back(avgYDirection);
    values.push_back(avgTimestamp);

    return values;
}

int ClusterTable::getSize() {
    return table.size();
}

std::string ClusterTable::getBestScoringNeighbor() {
    // Make sure the scores are up-to-date
    scoreNeighbors();

    // return closest neighbor to 0
    double closestScore = std::numeric_limits<double>::max();
    std::string closestEntry;

    for (const auto& entry : score) {
        double currentScore = std::abs(entry.second);
        if (currentScore < closestScore) {
            closestScore = currentScore;
            closestEntry = entry.first;
        }
    }

    return closestEntry;
}

std::vector<std::string> ClusterTable::getAllNeighbors() const {
    std::vector<std::string> keys;
    keys.reserve(table.size());

    for (const auto& entry : table) {
        keys.push_back(entry.first);
    }

    return keys;
}

// Reset the table to empty
void ClusterTable::resetTable() {
    table.clear();
}

// Print the scores of each neighbor
void ClusterTable::printScores() {
    cout << "Neighbor Scores:" << endl;
    for (const auto& entry : score) {
        cout << "Name: " << entry.first << ", Score: " << entry.second << endl;
    }
}

// Print the calculated averages
void ClusterTable::printAverages() {
    cout << "Calculated Averages:" << endl;
    cout << "Average Cars in Range: " << avgCarsInRange << endl;
    cout << "Average X Velocity: " << avgXVelocity << endl;
    cout << "Average Y Velocity: " << avgYVelocity << endl;
    cout << "Average Velocity: " << avgSignalStrength << endl;
    cout << "Average Speed: " << avgSpeed << endl;
    cout << "Average Acceleration: " << avgAcceleration << endl;
    cout << "Average Deceleration: " << avgDeceleration << endl;
    cout << "Average X Position: " << avgXPosition << endl;
    cout << "Average Y Position: " << avgYPosition << endl;
    cout << "Average X Direction: " << avgXDirection << endl;
    cout << "Average Y Direction: " << avgYDirection << endl;
    cout << "Centricity: " << centricity << endl;
}

// Print the table
void ClusterTable::printTable() {
    for (const auto& entry : table) {
        cout << "Name: " << entry.first << ", Speed: " << entry.second.speed
             << ", Cars in Range: " << entry.second.carsInRange
             << ", Velocity: " << entry.second.signalStrength
             << ", xVelocity: " << entry.second.xVelocity
             << ", yVelocity: " << entry.second.yVelocity
             << ", Acceleration: " << entry.second.acceleration
             << ", Deceleration: " << entry.second.deceleration
             << ", xPosition: " << entry.second.xPosition
             << ", yPosition: " << entry.second.yPosition
             << ", xDirection: " << entry.second.xDirection
             << ", yDirection: " << entry.second.yDirection
             << ", Timestamp: " << entry.second.timestamp << endl;
    }
}
