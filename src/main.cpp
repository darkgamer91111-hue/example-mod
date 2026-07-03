#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(MyLevelInfoLayer, LevelInfoLayer) {
    bool init(GJGameLevel* lvl, bool ch) {
        if (!LevelInfoLayer::init(lvl, ch)) return false;
        
        double pct = lvl->m_normalPercent;
        if (pct > 0.0) {
            auto lbl = typeinfo_cast<CCLabelBMFont*>(this->getChildByID("percentage-label"));
            if (lbl) {
                std::string txt = numToFormatedString(pct, 2) + "%";
                lbl->setString(txt.c_str());
            }
        }
        return true;
    }
};
