//
// Created by Zhou,Baochuan on 18/6/4.
//

#include "common.h"
#include <gtest/gtest.h>
#include <boost/progress.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost;
using namespace boost::gregorian;

// 时间进度条
TEST(timer, elapsed)
{
    vector<string> v(100, "aaa");
    v[1] = ""; v[53] = "";

    progress_display pd(v.size());
    vector<string>::iterator pos;
    for (pos = v.begin(); pos != v.end(); pos++) {
        ++pd;
        if (pos->empty()) {
            cout << "string empty : " << pos - v.begin() << endl;
        }
    }

}

// 日期展示
TEST(date, show)
{
    date d1(2018, 06, 02), d2(2018, 06, 04);
    // 计算相隔天数
    cout << "相隔天数:" << d2 - d1 << endl;

    // 今天
    date now(day_clock::local_day());
    cout << "今天:" << to_iso_extended_string(now) << endl;

    // 昨天
    date yesterday = now - days(1);
    cout << "昨天:" << to_iso_extended_string(yesterday) << endl;

    // 明天
    date tomorrow = now + days(1);
    cout << "明天:" << to_iso_extended_string(tomorrow) << endl;
}
