//
// Created by Zhou,Baochuan on 18/6/6.
//

#include "relation.h"
#include <boost/algorithm/string.hpp>
#include <regex>
#include <boost/foreach.hpp>
#include <gtest/gtest.h>

using namespace work;
using namespace boost::algorithm;

Relation::Relation() {
    this->init_map_family();
}

Relation::~Relation() {
}

void Relation::init_map_family() {
    string file_path = "./data/relation/D_map_family";
    ifstream in(file_path.c_str());
    ASSERT_FALSE(in.fail());
    string line;
    string relation_name; // 关系名
    string to_reverse_relation_name; // 对应的反向关系名
    vector<string> ret;
    int index = 0;
    while(getline(in, line, '\n')){
        if (index == 0) {
            index++;
            continue;
        }
        split(ret, line, boost::is_any_of("\t"));
        relation_name= ret[0];
        to_reverse_relation_name = ret[1];
        this->_map_famaily[relation_name] = to_reverse_relation_name;
    }
    in.close();
}

vector<RelationMap> Relation::regular_extract(const string &text) {
    vector<RelationMap> ret;

    vector<string> vecRole = StringUtil::split(text, "：");
    if (vecRole.size() < 2) {
        return ret;
    }

    vector<string> vecP2 = StringUtil::split(vecRole[1], "，|、");

    for (int i = 0; i < vecP2.size(); i++) {
        if (vecP2[i].empty()) {
            continue;
        }
        RelationMap relationMap;
        relationMap.L = vecRole[0];
        relationMap.P2 = vecP2[i];
        ret.push_back(relationMap);
    }

    return ret;
}

// 获取角色
string Relation::extract_L(ptree::value_type &node) {
    string L;
    string tag = node.second.get_child("tag").get_value<string>();
    if (equals(tag, "paragraph")) {
        return L;
    }

    if (equals(tag, "header")) {
        L = node.second.get_child("title").get_value<string>();
    } else if (equals(tag, "list")) {
        if (equals(node.second.get_child("type").get_value<string>(), "unordered")) {
            // 用于删除html标签正则
            regex rgx("<[a-zA-Z/]*>");
            // 遍历数组中的元素
            BOOST_FOREACH (ptree::value_type& v, node.second.get_child("list")) {
                BOOST_FOREACH (ptree::value_type& v1, v.second) {
                    if (equals(v1.second.get_child("tag").get_value<string>(), "text")) {
                        L = regex_replace(v1.second.get_child("text").get_value<string>(), rgx, "");
                    }
                }
            }
        }
    }
    if (this->_map_famaily.count(L) > 0) {
        return L;
    }
    return "";
}

// 获取人物名称
string extract_P2(string P1, string L, ptree::value_type &node) {
    string ret;

    // filter
    if (L.empty()) {
        return ret;
    }
    if (!equals(node.second.get_child("tag").get_value<string>(), "paragraph")) {
        return ret;
    }
    if (node.second.get_child("content").empty()) {
        return ret;
    }

    // 遍历数组中的元素
    BOOST_FOREACH (ptree::value_type& v, node.second.get_child("content")) {
        if (equals(v.second.get_child("tag").get_value<string>(), "innerlink")) {
            cout << "P1=" << P1 << "\tL=" << L << "\tP2=" << v.second.get_child("text").get_value<string>() << endl;
        }
    }

    return ret;
}

vector<RelationMap> Relation::regular_extract_wrap(const string &text) {
    vector<RelationMap> ret;
    stringstream str_stream(text);
    try {
        ptree root;
        read_json(str_stream, root);
        string P1 = root.get_child("lemmaTitle").get_value<string>();
        string L, P2;
        BOOST_FOREACH(ptree::value_type &v, root.get_child("contentStructured")) {
           if (!equals(v.second.get_child("tag").get_value<string>(), "paragraph")) {
               L = this->extract_L(v);
           } else {
               extract_P2(P1, L, v);
           }

        }
    } catch(ptree_error & e) {
        std::cout<<e.what()<<endl;
    } catch(runtime_error& e) {
        std::cout<<e.what()<<endl;
    }
    return ret;
}
