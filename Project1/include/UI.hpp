/* Created by BowenWu No.15331310
 * Contact me at wubw6@mail2.sysu.edu.cn
 * Code style requirement:
 * 1, good looking
 * 2, comment should be more than 30 percent;
 */
#ifndef UI
#define UI
#include "TrainManager.hpp"
class UI {
  public:
    void StartUI();
  private:
    bool whether_input_data;
    std::vector<Train> data;


    void OperationLoop();

    void getOperation();
    
    /* setTrainData
     * make sure client are inputing legal data
     */
    void setTrain();

    /* clear Train data
     * return operation loop
     */
    void clearTrain();

    /* before getInstruction
     * check whether our data is legal
     * check whether there is data
     */
    void getInstruction();

    /* quit UI
     * say goodbye or something
     */
    void quitUI();
};
#endif