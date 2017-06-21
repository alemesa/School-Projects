using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment_3_Final.Models;

namespace Assignment_3_Final.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        // AutoMapper instance
        public IMapper mapper;

        public Manager()
        {
            // If necessary, add more constructor code here...

            // Configure the AutoMapper components
            var config = new MapperConfiguration(cfg =>
            {
                // Define the mappings below, for example...
                // cfg.CreateMap<SourceType, DestinationType>();
                // cfg.CreateMap<Employee, EmployeeBase>();


                // For Employee
                cfg.CreateMap<Models.Employee, Controllers.EmployeeBase>();
                cfg.CreateMap<Controllers.EmployeeBase, Controllers.EmployeeEditContactInfoForm>();
                cfg.CreateMap<Controllers.EmployeeAdd, Models.Employee>();

                // For Tracks
                cfg.CreateMap<Models.Track, Controllers.TrackBase>();

            });

            mapper = config.CreateMapper();

            // Turn off the Entity Framework (EF) proxy creation features
            // We do NOT want the EF to track changes - we'll do that ourselves
            ds.Configuration.ProxyCreationEnabled = false;

            // Also, turn off lazy loading...
            // We want to retain control over fetching related objects
            ds.Configuration.LazyLoadingEnabled = false;
        }

        // Add methods below
        // Controllers will call these methods
        // Ensure that the methods accept and deliver ONLY view model objects and collections
        // The collection return type is almost always IEnumerable<T>

        // Suggested naming convention: Entity + task/action
        // For example:
        // ProductGetAll()
        // ProductGetById()
        // ProductAdd()
        // ProductEdit()
        // ProductDelete()

        // ############################################################
        // Employee
        // ############################################################

        // Get all Employees
        public IEnumerable<EmployeeBase> GetAll()
        {
            // The ds object is the data store
            // It has a collection for each entity it manages
            return mapper.Map<IEnumerable<Employee>, IEnumerable<EmployeeBase>>(ds.Employees);
        }

        // Get one Employee by its identifier
        public EmployeeBase GetOne(int id)
        {
            var o = ds.Employees.Find(id);

            return (o == null) ? null : mapper.Map<Employee, EmployeeBase>(o);
        }

        // Add new Employee
        public EmployeeBase EmployeeAdd(EmployeeAdd newItem)
        {

            var addedItem = ds.Employees.Add(mapper.Map<EmployeeAdd, Employee>(newItem));
            ds.SaveChanges();


            return (addedItem == null) ? null : mapper.Map<Employee, EmployeeBase>(addedItem);
        }

        //  06 - Edit Employee, contact info
        public EmployeeBase EmployeeEditContactInfo(EmployeeEditContactInfo newItem)
        {

            var o = ds.Employees.Find(newItem.EmployeeId);

            if (o == null)
            {

                return null;
            }
            else
            {

                ds.Entry(o).CurrentValues.SetValues(newItem);
                ds.SaveChanges();


                return mapper.Map<Employee, EmployeeBase>(o);
            }
        }

        //  07 - Delete Employee
        public bool EmployeeDelete(int id)
        {

            var itemToDelete = ds.Employees.Find(id);

            if (itemToDelete == null)
            {
                return false;
            }
            else
            {
                ds.Employees.Remove(itemToDelete);
                ds.SaveChanges();

                return true;
            }
        }

        // ############################################################
        // Track
        // ############################################################

        public IEnumerable<TrackBase> TrackGetAll()
        {
            var sorting = ds.Tracks.OrderBy(t => t.TrackId).ThenBy(t => t.GenreId);
            return mapper.Map<IEnumerable<Track>, IEnumerable<TrackBase>>(sorting);
        }

        public IEnumerable<TrackBase> TrackPop()
        {
            var sorting = ds.Tracks.Where(t => t.GenreId == 9).OrderBy(t => t.Name);
            return mapper.Map<IEnumerable<Track>, IEnumerable<TrackBase>>(sorting);
        }

        public IEnumerable<TrackBase> TrackDeepPurple()
        {
            var sorting = ds.Tracks.Where(t => t.Composer.Contains("Jon Lord")).OrderBy(t => t.TrackId);
            return mapper.Map<IEnumerable<Track>, IEnumerable<TrackBase>>(sorting);
        }

        public IEnumerable<TrackBase> TrackLongest()
        {
            var sorting = ds.Tracks.OrderByDescending(t => t.Milliseconds).Take(100);
            return mapper.Map<IEnumerable<Track>, IEnumerable<TrackBase>>(sorting);
        }




    }
}