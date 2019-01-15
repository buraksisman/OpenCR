/*******************************************************************************
* Copyright 2018 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/* Authors: Darby Lim, Hye-Jong KIM, Ryan Shim, Yong-Ho Na */

#include <Planar.h>
#include "RemoteController100.h"
#include "Processing.h"
#include "Demo.h"

Planar planar;

void setup()
{
  /**
   */
  planar.initDebug();


  /**
   */
  initRC100();       


  /**
   */
  initProcessing();  


  /**
   */
  initDemo();


  while (!Serial);     

  /**
   */
  planar.initManipulator(true); // true: using actual hardware
                                // false: using only visualization tool 

}

void loop()
{
  /**
   */
  receiveDataFromRC100(&planar);      


  /**
   */
  receiveDataFromProcessing(&planar); 
  sendDataToProcessing(&planar); 


  /**
   */
  planar.executeData();    


  /**
   */
  executeDemo(&planar); 
}