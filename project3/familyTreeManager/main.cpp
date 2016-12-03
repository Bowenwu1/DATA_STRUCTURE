#include"familyTree.h"

int main() {
    familyTree ft("wubowen", true, "19970125");
	Person changgui("changgui", "19960517", true);
	Person yaoming("yaoming", "19960000", true);
	ft.addWife(yaoming, ft.getIdByName("wubowen"));
	ft.addBaby(changgui, ft.getIdByName("yaoming"));
	ft.print(ft.getRoot());
    return 0;
}
