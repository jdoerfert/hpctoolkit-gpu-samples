/*****************************************************************************
*
* Copyright (c) 2000 - 2014, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-442911
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

// ************************************************************************* //
//                            avtsw4imgFileFormat.h                           //
// ************************************************************************* //

#ifndef AVT_sw4img_FILE_FORMAT_H
#define AVT_sw4img_FILE_FORMAT_H

#include <avtSTMDFileFormat.h>

#include <vector>
#include <string>


// ****************************************************************************
//  Class: avtsw4imgFileFormat
//
//  Purpose:
//      Reads in sw4img files as a plugin to VisIt.
//
//  Programmer: petersson1 -- generated by xml2avt
//  Creation:   Tue Nov 11 12:42:37 PDT 2014
//
// ****************************************************************************

class avtsw4imgFileFormat : public avtSTMDFileFormat
{
  public:
                       avtsw4imgFileFormat(const char *);
    virtual           ~avtsw4imgFileFormat() {;};

    //
    // This is used to return unconvention data -- ranging from material
    // information to information about block connectivity.
    //
    // virtual void      *GetAuxiliaryData(const char *var, int domain,
    //                                     const char *type, void *args, 
    //                                     DestructorFunction &);
    //

    //
    // If you know the cycle number, overload this function.
    // Otherwise, VisIt will make up a reasonable one for you.
    //
    // virtual int         GetCycle(void);
    //

    virtual const char    *GetType(void)   { return "sw4img"; };
    virtual void           FreeUpResources(void); 

    virtual vtkDataSet    *GetMesh(int, const char *);
    virtual vtkDataArray  *GetVar(int, const char *);
    virtual vtkDataArray  *GetVectorVar(int, const char *);

  protected:
    // DATA MEMBERS

    virtual void           PopulateDatabaseMetaData(avtDatabaseMetaData *);

    // imagevolume data
    void Initialize();
    bool m_initialized;
    bool m_data_stored;
    bool m_CartGrid;
//    bool m_grid_stored; // not currently used
    double m_time;
    std::vector<float*> m_dataptr;
    std::vector<float*> m_gridptr;
    std::string m_filename;
//    std::string m_gridname; // not needed anymore?
//    std::string m_gridfilename; // not needed anymore?
    int m_prec;
    int m_nblocks; // total number of data patches on file (the grid data is not considered a separate patch)
    int m_gridOffset; // file offset to grid z-coords (if m_grdinfo == 1)
//    int m_nAllBlocks; // total number of patches on file (including the grid patch if it exists)
    
    int m_plane;
    double m_plane_coord;
    int m_mode_number;
    int m_grdinfo;
    std::string m_file_creation_time;
    
    std::vector<double> m_gridsize;
    std::string m_mode;
    std::vector<double> m_xmin;
    std::vector<double> m_ymin;
    std::vector<double> m_zmin;
    std::vector<double> m_z0;
    std::vector<int> m_ni;
    std::vector<int> m_nj;
    std::vector<int> m_nk;
    std::vector<off_t> m_offset;
//    std::vector<off_t> m_gridoffset; // not needed since we do not read a separate gridd file anymore

};


#endif
