#ifndef DATASTORE_HPP
#define DATASTORE_HPP

#include <iostream>
#include <fstream>
#include "dataclasses.hpp"
#include <filesystem>
#include "nlohmann/json.hpp"

using json = nlohmann::json;


//Helper functions
//This function reads a JSON file and returns
json readJsonFromFile(const std::string& filePath) {
        if (!std::filesystem::exists(filePath)) {
        throw std::runtime_error("File does not exist: " + filePath);}
    
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filePath);}
        json jsonData;
        file >> jsonData;
        return jsonData;}

class DataStore {
public:
    std::vector<CourseCatalog> catalog_Data;
    std::vector<MetaData> meta_Data;
    std::vector<DegreeAudit> degree_Data;
    
    // When a new DataStore object is created, it will load the data from the JSON files
    // What is returned is a vector of CourseCatalog, MetaData, and DegreeAudit objects
    std::vector<CourseCatalog> get_CatalogData() const { return catalog_Data; }
    std::vector<MetaData> get_MetaData() const { return meta_Data; }
    std::vector<DegreeAudit> get_DegreeData() const { return degree_Data; }
    
    DataStore() {}

    DataStore(
    std::vector<CourseCatalog>& catalogData,
    std::vector<MetaData>& metaData,
    std::vector<DegreeAudit>& degreeData)
    : catalog_Data(catalogData), meta_Data(metaData), degree_Data(degreeData) {}

    void load_catalog_Data() 
    {
            try {
        json jsonData = readJsonFromFile("../../data/CatalogData.json");

        for ( auto& courseData : jsonData) 
        {
            CourseCatalog course(
                courseData.value("dept", ""), 
                courseData.value("course_number", 0),
                courseData.value("course_name", ""), 
                courseData.value("credits", 0),
                courseData.value("start_time", ""), 
                courseData.value("end_time", ""), 
                courseData.value("days", ""));
            catalog_Data.push_back(course);
        }
    } catch (const nlohmann::json::parse_error& e) {
        std::cerr << "JSON Parsing Error: " << e.what() << std::endl;
        
    } catch (const nlohmann::json::type_error& e) {
        std::cerr << "JSON Type Error: " << e.what() << std::endl;
        
    } catch (const nlohmann::json::exception& e) {
        std::cerr << "JSON Exception: " << e.what() << std::endl;
                }
    }

    void load_meta_Data() 
    {
            try {
        json jsonData = readJsonFromFile("../../data/CourseMetaData.json");

        for (auto& courseData : jsonData) 
        {
            MetaData course(
                courseData.value("dept", ""), 
                courseData.value("course_number", 0),
                courseData.value("prerequisites", std::vector<int>{}),
                courseData.value("fallOnly", false),
                courseData.value("springOnly", false),
                courseData.value("workload", 0),
                courseData.value("groupProject", false),
                courseData.value("attendanceGrade", false));
            meta_Data.push_back(course);
        }
    } catch (const nlohmann::json::parse_error& e) {
        std::cerr << "JSON Parsing Error: " << e.what() << std::endl;
        
    } catch (const nlohmann::json::type_error& e) {
        std::cerr << "JSON Type Error: " << e.what() << std::endl;
        
    } catch (const nlohmann::json::exception& e) {
        std::cerr << "JSON Exception: " << e.what() << std::endl;
                }
    }

    void load_degree_Data() {
            try {
        json jsonData = readJsonFromFile("../../data/DegreeAuditData.json");

        for ( auto& courseData : jsonData) {
            DegreeAudit course(
                courseData.value("dept", ""),
                courseData.value("course_number", 0),
                courseData.value("iscomplete", false));
            degree_Data.push_back(course);
            }
    } catch (const nlohmann::json::parse_error& e) {
        std::cerr << "JSON Parsing Error: " << e.what() << std::endl;
        
    } catch (const nlohmann::json::type_error& e) {
        std::cerr << "JSON Type Error: " << e.what() << std::endl;
        
    } catch (const nlohmann::json::exception& e) {
        std::cerr << "JSON Exception: " << e.what() << std::endl;}
    }

    void load_all_Data() {
        load_catalog_Data();
        load_meta_Data();
        load_degree_Data();
    }

    friend std::ostream& operator<<(std::ostream& os, const DataStore& data) {
        for (const auto& course : data.get_CatalogData()) {
            os << course << std::endl;
        }
        for (const auto& course : data.get_MetaData()) {
            os << course << std::endl;
        }
        for (const auto& course : data.get_DegreeData()) {
            os << course << std::endl;
        }
        return os;
    }

    void print_all() const {
        std::cout << *this;
    }

    // Resets the DataStore to an empty state
    void clear() {
        catalog_Data.clear();
        meta_Data.clear();
        degree_Data.clear();
    }

    

    

};

#endif