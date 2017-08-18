/*=========================================================================

  Program:   Visualization Toolkit

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRFollower
 * @brief   OpenVR Follower
 *
 * vtkOpenVRFollower a follower that aligns with PhysicalViewUp
*/

#ifndef vtkOpenVRFollower_h
#define vtkOpenVRFollower_h

#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkFollower.h"

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRFollower : public vtkFollower
{
public:
  static vtkOpenVRFollower *New();
  vtkTypeMacro(vtkOpenVRFollower, vtkFollower);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  virtual void Render(vtkRenderer *ren) VTK_OVERRIDE;

  /**
   * Generate the matrix based on ivars. This method overloads its superclasses
   * ComputeMatrix() method due to the special vtkFollower matrix operations.
   */
  void ComputeMatrix() VTK_OVERRIDE;

protected:
  vtkOpenVRFollower();
  ~vtkOpenVRFollower();

  double LastViewUp[3];

private:
  vtkOpenVRFollower(const vtkOpenVRFollower&) VTK_DELETE_FUNCTION;
  void operator=(const vtkOpenVRFollower&) VTK_DELETE_FUNCTION;
};

#endif