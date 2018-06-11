//
// Created by Zhou,Baochuan on 18/6/6.
//

#ifndef WORK_RELATION_H
#define WORK_RELATION_H
#include "common.h"
#include "string_util.h"
#include <boost/property_tree/json_parser.hpp>
using namespace boost::property_tree;
namespace work {
    // 人物关系:三元关系
    struct RelationMap{
        string P1;
        string P2;
        string L;
    };

    class Relation {
    public:
        Relation();
        ~Relation();
        // 初始化家庭成员映射关系
        void init_map_family();
        // 规则提取
        string extract_L(ptree::value_type &node);
        vector<RelationMap> regular_extract(const string &text);
        vector<RelationMap> regular_extract_wrap(const string &text);
    private:
        //
        map<string, string> _map_famaily;
        // 已经有的三元关系
        map<string, string> _map_had_relation;
    };
}
#endif //WORK_RELATION_H
