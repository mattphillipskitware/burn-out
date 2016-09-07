/*ckwg +5
 * Copyright 2010 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */


#include <logger/vidtk_logger.h>

#include <logger/logger_manager.h>
#include <vbl/vbl_smart_ptr.hxx>


namespace vidtk {

// ----------------------------------------------------------------
/** Constructor.
 *
 *
 */
vidtk_logger
::vidtk_logger(const char * const realm)
  : m_parent(0)
{
  m_loggingRealm = realm;
  m_parent = ::vidtk::logger_manager::instance(); // currently only one parent possible
}


vidtk_logger
::vidtk_logger( vcl_string const& realm)
  : m_parent(0)
{
  m_loggingRealm = realm;
  m_parent = ::vidtk::logger_manager::instance(); // currently only one parent possible
}


vidtk_logger
:: ~vidtk_logger()
{

}


// ----------------------------------------------------------------
/** Convert level code to string.
 *
 *
 */
char const* vidtk_logger
::get_level_string(vidtk_logger::log_level_t lev) const
{
  switch (lev)
  {
  case vidtk_logger::LEVEL_TRACE:  return "TRACE";
  case vidtk_logger::LEVEL_DEBUG:  return "DEBUG";
  case vidtk_logger::LEVEL_INFO:   return "INFO";
  case vidtk_logger::LEVEL_WARN:   return "WARN";
  case vidtk_logger::LEVEL_ERROR:  return "ERROR";
  case vidtk_logger::LEVEL_FATAL:  return "FATAL";

  default:           break;
  } // end switch

    return "<unknown>";
}


vcl_string vidtk_logger
::get_name()
{
  return m_loggingRealm;
}


} // end namespace

VBL_SMART_PTR_INSTANTIATE( ::vidtk::vidtk_logger );

